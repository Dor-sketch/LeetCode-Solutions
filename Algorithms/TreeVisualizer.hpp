#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>

class TreeVisualizer {
  public:
    struct NodeInfo {
        int level;
        int parent;
    };

    TreeVisualizer(const std::vector<NodeInfo> &path) : shortest_path(path) {
        depth = calculateTreeDepth();
        width = calculateTreeWidth();
        generateLevelMap();
        calculateNodePositions();
        reconstructTree();
    }

    ~TreeVisualizer() {
        // Clean up dynamically allocated nodes
        for (auto node : indexToNode) {
            delete node;
        }
    }

    void visualizeTree() {
        if (indexToNode.empty())
            return;
        Node *root = indexToNode[0]; // Assuming 0 is the root index
        if (root == nullptr)
            return;
        std::set<Node *> visited;    // To keep track of visited nodes
        root->printTree(visited);
    }

  private:
    class Node {
      public:
        Node(std::string val) : val(val) {}
        std::vector<Node *> _children;
        std::string val;


        void printTree(std::set<Node *> &visited) {
            using std::cout;
            cout << val << "\n";
            printSubtree("", visited);
            cout << "\n";
        }

        void printSubtree(const std::string &prefix,
                          std::set<Node *> &visited) {
            if (!visited.insert(this).second) {
                // Node already visited, possibly a cycle
                return;
            }

            size_t n_children = _children.size();
            if (n_children == 0)
                return;

            for (size_t i = 0; i < n_children; ++i) {
                Node *c = _children[i];
                bool isLastChild = (i == n_children - 1);

                // Determine the branch type
                std::string branch = isLastChild ? "└── " : "├── ";

                // Calculate the dynamic indentation
                int nonSpaceChars =
                    std::count_if(prefix.begin(), prefix.end(),
                                  [](char c) { return c != ' '; })+1;

                std::string indent =
                    std::string(std::max(0, 4 - nonSpaceChars), ' ');
                std::string lineConnector = isLastChild ? " " : "|";
                std::string childPrefix = prefix + lineConnector + indent;

                std::cout << prefix << branch << c->val << "\n";
                c->printSubtree(childPrefix, visited);
            }
        }
    };

    const std::vector<NodeInfo> &shortest_path;
    std::vector<Node *> indexToNode;
    int depth, width;
    std::map<int, std::vector<int>> levelMap; // Maps level to nodes
    std::map<int, int> nodePositions; // Maps node to its horizontal position

    void reconstructTree() {
        indexToNode.resize(shortest_path.size(), nullptr);

        // Create Node objects for each index
        for (int i = 0; i < shortest_path.size(); ++i) {
            indexToNode[i] = new Node(std::to_string(i));
        }

        // Set up child relationships
        for (int i = 0; i < shortest_path.size(); ++i) {
            int parentIndex = shortest_path[i].parent;
            // avoid adding the root as a child
            if (parentIndex != -1) {
                // Add the current node as a child of its parent
                indexToNode[parentIndex]->_children.push_back(indexToNode[i]);
            }
        }
    }

    int calculateTreeDepth() {
        int maxDepth = 0;
        for (const auto &node : shortest_path) {
            maxDepth = std::max(maxDepth, node.level);
        }
        return maxDepth + 1;
    }

    int calculateTreeWidth() {
        return (1 << (depth - 1)) * 3; // Width is calculated based on depth
    }

    void generateLevelMap() {
        for (int i = 0; i < shortest_path.size(); ++i) {
            levelMap[shortest_path[i].level].push_back(i);
        }
    }

    void calculateNodePositions() {
        int rootPos = width / 2;
        nodePositions[0] = rootPos; // Assuming node 0 is the root

        for (int level = 1; level < depth; ++level) {
            int space = (1 << (depth - level - 1)) * 3;
            for (int i = 0; i < levelMap[level].size(); ++i) {
                int node = levelMap[level][i];
                int parent = shortest_path[node].parent;
                int offset = (i % 2 == 0) ? -space / 2 : space / 2;
                nodePositions[node] = nodePositions[parent] + offset;
            }
        }
    }
};
