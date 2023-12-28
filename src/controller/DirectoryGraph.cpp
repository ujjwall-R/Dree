#include "DirectoryGraph.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include<filesystem>
#include<queue>
using namespace std;

DirectoryGraph::DirectoryGraph(bool showHidden) : p(0),showHidden(showHidden), excludedDirectories() {
    ifstream file(".dreeignore");
    string line;
    while (getline(file, line)) {
        this->excludedDirectories.insert(line);
    }

    this->allFilesPermited = true;
    this->permissionErrorString = "Note:- Somefiles were omited due to default permission errors!!";
}

bool DirectoryGraph::isDirectory(const string &pathStr) {
    filesystem::path path(pathStr);
    return filesystem::is_directory(path);
}

bool DirectoryGraph::isExcluded(const string &dirStr) {
    return (dirStr.front() == '.' || excludedDirectories.find(dirStr) != excludedDirectories.end());
}

DirectoryNode *DirectoryGraph::BuildGraph(const string &directoryName, long long depth) {
    DirectoryNode *graph = new DirectoryNode(directoryName);
    TraverseDirectoriesDFS(graph, depth,1);
    return graph;
}

void DirectoryGraph::TraverseDirectoriesDFS(DirectoryNode *node, long long depth, long long currentDepth) {
    try {
        for (const auto &entry : filesystem::directory_iterator(node->path)) {
            if (!showHidden && isExcluded(entry.path().filename().string())) continue;

            string childDirectory = entry.path().string();
            DirectoryNode *child = new DirectoryNode(childDirectory);
            node->children.push_back(child);
        }
    } catch (const std::exception &e) {
        this->allFilesPermited = false;
    }
    if (currentDepth == depth||node->children.empty()){
        node->pos=p;
        p=max(p,(long long)(node->pos+node->name.size()+5));
        return ;
    }
    for (auto ch : node->children) {
        TraverseDirectoriesDFS(ch, depth, currentDepth + 1);
    }
    node->pos=(node->children[0]->pos+node->children.back()->pos)/2;
    p=max(p,(long long)(node->pos+node->name.size()+5));
}
void DirectoryGraph::PrintGraphDFS(DirectoryNode *node, long long depth, long long currentDepth, bool isLastChild,long long mask) {
    if (currentDepth == depth) return;

    for (long long i = 0; i < currentDepth; i++) {
        if (((mask >> i) & 1ll) == 0ll)
            cout << "│   ";
        else
            cout << "    ";
    }
    isLastChild ? cout << "└──" : cout << "├──";

    cout <<node->name << "\n";
    for (size_t i = 0; i < node->children.size(); i++) {
        DirectoryNode *child = node->children[i];
        if (i == node->children.size() - 1) {
            mask = mask | (1ll << (currentDepth + 1));
        }
        PrintGraphDFS(child, depth, currentDepth + 1, i == node->children.size() - 1, mask);
    }
}

void DirectoryGraph::PrintGraphDFS(DirectoryNode *node, long long depth) {
    this->PrintGraphDFS(node, depth, 0ll, true, 1ll);
}
void DirectoryGraph::print_char(FILE* st,const char* c){
    if(!st){
        cout<<c;
    }
    fprintf(st,"%s",c);
}
void DirectoryGraph::print_name(FILE* st,queue<DirectoryNode*>& q,long long depth){
    long long len=q.size();
    long long pos=0;
    while(len){
        if(pos==q.front()->pos){
            DirectoryNode* node=q.front();
            q.pop();
            print_char(st,node->name.c_str());
            pos+=node->name.size();
            q.push(node);
            len--;
        }
        else{
            print_char(st," ");
            pos++;
        }
    }
    print_char(st,"\n");
}
void DirectoryGraph::print_line(FILE* st,queue<DirectoryNode*>& q,long long depth){
    if(!(depth-1)){
        return ;
    }
    long long len=q.size();
    long long pos=0;
    while(len){
        DirectoryNode* node=q.front();
        q.pop();
        queue<int> temp;
        for(auto ch:node->children){
            temp.push(ch->pos);
        }
        bool sw=true;
        while(!temp.empty()){
            if(pos==node->pos){
                if(pos==temp.front()){
                    if(node->children.size()==1){
                        print_char(st,"│");
                    }
                    else{
                        print_char(st,"┼");
                    }
                    temp.pop();
                }
                else{
                    print_char(st,"┴");
                }
            }
            else if(pos==temp.front()){
                if(pos==node->children[0]->pos){
                    print_char(st,"┌");
                    sw=false;
                }
                else if(pos==node->children.back()->pos){
                    print_char(st,"┐");
                }
                else{
                    print_char(st,"┬");
                }
                temp.pop();
            }
            else if(sw){
                print_char(st," ");
            }
            else{
                print_char(st,"─");
            }
            pos++;
        }
        q.push(node);
        len--;
    }
    print_char(st,"\n");
}
void DirectoryGraph::PrintGraphBFS(DirectoryNode* node,long long depth){
    FILE* st=popen("less -S","w");
    queue<DirectoryNode*> q;
    q.push(node);
    while(depth&&!q.empty()){
        print_name(st,q,depth);
        print_line(st,q,depth);
        long long len=q.size();
        while(len){
            DirectoryNode* node=q.front();
            q.pop();
            for(auto ch:node->children){
                q.push(ch);
            }
            len--;
        }
        depth--;
    }
    pclose(st);
}
void DirectoryGraph::TraverseDirectoriesToSearch(DirectoryNode *node, long long depth, long long currentDepth,
                                                 const string &query, vector<pair<int, DirectoryNode *>> &results) {
    if (currentDepth > depth) return;

    int score1 = DirectorySearch::LevenshteinDistance(node->name, query);
    int score2 = DirectorySearch::LevenshteinDistance(node->path, query);
    if (score1 * 100 <= (50 * query.length()) || score2 * 100 <= (50 * query.length())) {
        results.push_back({min(score1, score2), node});
    }

    if (!isDirectory(node->path)) {
        return;
    }

    try {
        for (const auto &entry : filesystem::directory_iterator(node->path)) {
            string childDirectory = entry.path().string();
            DirectoryNode *child = new DirectoryNode(childDirectory);
            node->children.push_back(child);
            TraverseDirectoriesToSearch(child, depth, currentDepth + 1, query, results);
        }
    } catch (const std::exception &e) {
    }
}

void DirectoryGraph::SearchDirectory(const string &directoryName, int searchDepth, const string &query) {
    DirectoryNode *currDir = new DirectoryNode(directoryName);
    DirectorySearch *searchObject = new DirectorySearch(searchDepth);
    this->TraverseDirectoriesToSearch(currDir, searchDepth, 0, query, searchObject->results);
    sort(searchObject->results.begin(), searchObject->results.end());
    if (searchObject->results.empty()) {
        cout << "No results found\n";
    } else {
        if (searchObject->results[0].first == 0) {
            cout << "Search Results:\n";
            int cnt = 0;
            for (auto res : searchObject->results) {
                if (res.first > 0) break;

                cout << cnt + 1 << ".\t";
                cout << res.second->name << "\t\t" << res.second->path << "\n";
                cnt++;
            }
        } else {
            cout << "Couldn't find results. Did you mean?:\n";
            int cnt = 0;
            for (auto res : searchObject->results) {
                cout << cnt + 1 << ".\t";
                cout << res.second->name << "\t\t" << res.second->path << "\n";
                cnt++;
            }
        }
    }
}