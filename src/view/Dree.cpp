#include "Dree.h"

void Dree::PrintGraph()
{
    for (const auto &node : graph)
    {
        cout << "└─ " << node.name << " (" << node.path << ")" << endl;
        PrintChildren(node.children, 1);
    }
}

void Dree::PrintChildren(const vector<DirectoryNode> &children, int level)
{
    if (level == depth)
        return;

    for (size_t i = 0; i < children.size(); ++i)
    {
        const auto &child = children[i];

        // Print indentation for the current level
        for (int j = 0; j < level; j++)
        {
            if (i == (int)children.size() - 1)
            {
                cout << "    ";
            }
            else
            {
                cout << "│   ";
            }
        }

        if (i == children.size() - 1)
        {
            cout << "└── ";
        }
        else
        {
            cout << "├── ";
        }

        cout << child.name << " (" << child.path << ")" << endl;

        PrintChildren(child.children, level + 1);
    }
}
