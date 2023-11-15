#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>

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
    }

    void visualizeTree() {
        std::string treeRepresentation = buildTreeRepresentation();
        std::cout << treeRepresentation;
    }

  private:
    const std::vector<NodeInfo> &shortest_path;
    int depth, width;
    std::map<int, std::vector<int>> levelMap; // Maps level to nodes
    std::map<int, int> nodePositions; // Maps node to its horizontal position

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

    std::string buildTreeRepresentation() {
        std::stringstream ss;
        const int nodeWidth = 3; // Width of a node representation

        for (int level = 0; level < depth; ++level) {
            std::string nodesLine, linesLine;

            for (int node : levelMap[level]) {
                int pos = nodePositions[node];
                nodesLine += std::string(pos - nodesLine.length(), ' ') + "(" +
                             std::to_string(node) + ")";

                if (level < depth - 1 && !levelMap[level + 1].empty()) {
                    int childIndex = 0;
                    for (int child : levelMap[level + 1]) {
                        if (shortest_path[child].parent == node) {
                            int childPos = nodePositions[child];
                            if (childIndex == 0) { // left child
                                linesLine +=
                                    std::string(pos - linesLine.length(), ' ') +
                                    "/";
                            } else { // right child
                                linesLine +=
                                    std::string(childPos - linesLine.length() -
                                                    1,
                                                ' ') +
                                    "\\";
                            }
                            childIndex++;
                        }
                    }
                }
            }

            ss << nodesLine << '\n';
            if (!linesLine.empty()) {
                ss << linesLine << '\n';
            }
        }

        return ss.str();
    }
};