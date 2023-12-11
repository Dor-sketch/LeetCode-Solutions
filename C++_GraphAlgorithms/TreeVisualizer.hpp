#pragma once

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class TreeVisualizer {
  public:
    struct NodeInfo {
        int level;
        int parent;
    };

    explicit TreeVisualizer(const std::vector<NodeInfo> &path)
        : shortest_path(path), depth(calculateTreeDepth()) {
        reconstructTree();
    }

    ~TreeVisualizer() {
        for (auto &node : indexToNode) {
            delete node;
        }
    }

    void visualizeTree() const {
        if (indexToNode.empty())
            return;

        Node *root = indexToNode[0];
        if (root == nullptr)
            return;

        std::set<Node *> visited;
        root->printTree(visited);
    }

  private:
    class Node {
      public:
        explicit Node(std::string val) : val(std::move(val)) {}
        std::vector<Node *> children;
        std::string val;

        void printTree(std::set<Node *> &visited)  {
            std::cout << val << "\n";
            printSubtree("", visited);
            std::cout << "\n";
        }

        void printSubtree(const std::string &prefix,
                          std::set<Node *> &visited)  {
            if (!visited.insert(this).second) {
                return; // Node already visited, possibly a cycle
            }

            for (size_t i = 0; i < children.size(); ++i) {
                Node *child = children[i];
                bool isLastChild = (i == children.size() - 1);
                std::string branch = isLastChild ? "└── " : "├── ";
                std::string childPrefix =
                    prefix + (isLastChild ? "    " : "|   ");
                std::cout << prefix << branch << child->val << "\n";
                child->printSubtree(childPrefix, visited);
            }
        }
    };

    const std::vector<NodeInfo> &shortest_path;
    std::vector<Node *> indexToNode;
    int depth;

    int calculateTreeDepth() const {
        int maxDepth = 0;
        for (const auto &node : shortest_path) {
            maxDepth = std::max(maxDepth, node.level);
        }
        return maxDepth + 1;
    }

    void reconstructTree() {
        indexToNode.resize(shortest_path.size(), nullptr);

        for (size_t i = 0; i < shortest_path.size(); ++i) {
            indexToNode[i] = new Node(std::to_string(i));
        }

        for (size_t i = 0; i < shortest_path.size(); ++i) {
            int parentIndex = shortest_path[i].parent;
            if (parentIndex != -1) {
                indexToNode[parentIndex]->children.push_back(indexToNode[i]);
            }
        }
    }
};
