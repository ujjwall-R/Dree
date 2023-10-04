#include "DirectoryGraph.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

DirectoryGraph::DirectoryGraph(std::set<std::string> &exludedDirectories)
    : excludedDirectories(exludedDirectories)
{
    this->allFilesPermited = true;
    this->permissionErrorString = "Note:- Somefiles were omited due to default permission errors!!";
}

bool DirectoryGraph::isDirectory(const string &pathStr)
{
    filesystem::path path(pathStr);
    return filesystem::is_directory(path);
}

bool DirectoryGraph::isExcluded(const string &dirStr)
{
    return (dirStr.front() == '.' || excludedDirectories.find(dirStr) != excludedDirectories.end());
}

DirectoryNode *DirectoryGraph::BuildGraph(const string &directoryName, long long depth)
{
    DirectoryNode *graph = new DirectoryNode(directoryName);
    TraverseDirectoriesDFS(graph, depth, 0);
    return graph;
}

void DirectoryGraph::TraverseDirectoriesDFS(DirectoryNode *node, long long depth, long long currentDepth)
{
    if (currentDepth > depth)
        return;

    try
    {
        for (const auto &entry : filesystem::directory_iterator(node->path))
        {
            if (!isExcluded(entry.path().filename().string()))
            {
                string childDirectory = entry.path().string();
                DirectoryNode *child = new DirectoryNode(childDirectory);
                node->children.push_back(child);
            }
        }
    }
    catch (const std::exception &e)
    {
        this->allFilesPermited = false;
    }

    for (auto ch : node->children)
    {
        if (isDirectory(ch->path))
        {
            TraverseDirectoriesDFS(ch, depth, currentDepth + 1);
        }
    }
}

void DirectoryGraph::PrintGraphDFS(DirectoryNode *node, long long depth, long long currentDepth, bool isLastChild, long long mask)
{
    if (currentDepth == depth)
        return;

    for (long long i = 0; i < currentDepth; i++)
    {
        if (((mask >> i) & 1ll) == 0ll)
            cout << "│    ";
        else
            cout << "     ";
    }
    isLastChild ? cout << "└── " : cout << "├── ";

    cout << node->name << "\n";
    for (size_t i = 0; i < node->children.size(); i++)
    {
        DirectoryNode *child = node->children[i];
        if (i == node->children.size() - 1)
        {
            mask = mask | (1ll << (currentDepth + 1));
        }
        PrintGraphDFS(child, depth, currentDepth + 1, i == node->children.size() - 1, mask);
    }
}

void DirectoryGraph::PrintGraphDFS(DirectoryNode *node, long long depth)
{
    this->PrintGraphDFS(node, depth, 0ll, true, 1ll);
}

void DirectoryGraph::TraverseDirectoriesToSearch(DirectoryNode *node, long long depth, long long currentDepth, const string &query, vector<pair<int, DirectoryNode *>> &results)
{
    if (currentDepth > depth)
        return;

    int score1 = DirectorySearch::LevenshteinDistance(node->name, query);
    int score2 = DirectorySearch::LevenshteinDistance(node->path, query);
    if (score1 * 100 <= (50 * query.length()) || score2 * 100 <= (50 * query.length()))
    {
        results.push_back({min(score1, score2), node});
    }

    if (!isDirectory(node->path))
    {
        return;
    }

    try
    {
        for (const auto &entry : filesystem::directory_iterator(node->path))
        {
            string childDirectory = entry.path().string();
            DirectoryNode *child = new DirectoryNode(childDirectory);
            node->children.push_back(child);
            TraverseDirectoriesToSearch(child, depth, currentDepth + 1, query, results);
        }
    }
    catch (const std::exception &e)
    {
    }
}

void DirectoryGraph::SearchDirectory(const string &directoryName, int searchDepth, const string &query)
{
    DirectoryNode *currDir = new DirectoryNode(directoryName);
    DirectorySearch *searchObject = new DirectorySearch(searchDepth);
    this->TraverseDirectoriesToSearch(currDir, searchDepth, 0, query, searchObject->results);
    sort(searchObject->results.begin(), searchObject->results.end());
    if (searchObject->results.empty())
    {
        cout << "No results found\n";
    }
    else
    {
        if (searchObject->results[0].first == 0)
        {
            cout << "Search Results:\n";
            int cnt = 0;
            for (auto res : searchObject->results)
            {
                if (res.first > 0)
                    break;

                cout << cnt + 1 << ".\t";
                cout << res.second->name << "\t\t"
                     << res.second->path
                     << "\n";
                cnt++;
            }
        }
        else
        {
            cout << "Couldn't find results. Did you mean?:\n";
            int cnt = 0;
            for (auto res : searchObject->results)
            {
                cout << cnt + 1 << ".\t";
                cout << res.second->name << "\t\t"
                     << res.second->path
                     << "\n";
                cnt++;
            }
        }
    }
}
