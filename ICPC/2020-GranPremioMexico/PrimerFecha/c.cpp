#include <bits/stdc++.h>

using namespace std;

struct Graph{
    struct Node {
        vector<string> neighbors;
        bool visited;
        string bestSolution;

        Node() {
            visited = false;
        }
    };

    unordered_map<string, Node> nodes;

    Graph() {}

    void join(string &u, string &v) {
        nodes[u].neighbors.push_back(v);
        nodes[v].neighbors.push_back(u);
    }

    string BFS(string &start) {
        queue<string> Queue;
        nodes[start].visited = true;
        Queue.push(start);
        string bestAnswer = start;
        string currentWord;
        while(!Queue.empty()) {
            currentWord = Queue.front();

            if(bestAnswer.size() > currentWord.size())
                bestAnswer = currentWord;
            else if(bestAnswer.size() == currentWord.size() and bestAnswer > currentWord)
                bestAnswer = currentWord;
    
            Queue.pop();
            for(const string &word : nodes[currentWord].neighbors) {
                if(!nodes[word].visited) {
                    Queue.push(word);
                    nodes[word].visited = true;
                }
            }
        }
        return bestAnswer;
    }

    void setBestSolutionPerComponent(string &start, string &bestSolution) {
        queue<string> Queue;
        nodes[start].visited = true;
        Queue.push(start);
        string currentWord;

        while(!Queue.empty()) {
            currentWord = Queue.front();
            Queue.pop();

            nodes[currentWord].bestSolution = bestSolution;

            for(const string &word : nodes[currentWord].neighbors) {
                if(!nodes[word].visited) {
                    Queue.push(word);
                    nodes[word].visited = true;
                }
            }
        }
    }
    
    void resetNodes() {
        for(auto &node : nodes)
            node.second.visited = false;
    }

    void traverseComponents() {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);

        vector<string> startPoint;
        for(auto &node : nodes) {
            if(!node.second.visited) {
                startPoint.push_back(node.first);
                string word = node.first;
                node.second.bestSolution = BFS(word);
            }
        }

        resetNodes();

        for(string &word : startPoint) {
            setBestSolutionPerComponent(word, nodes[word].bestSolution);
        }
    }
};

int main() {
    Graph graph;
    int numberOfPairs;
    string key, value, text, token;
    vector<string> tokens;

    cin >> numberOfPairs;

    while(numberOfPairs--) {
        cin >> key >> value;
        graph.join(key, value);
    }


    while(cin >> token) 
        tokens.push_back(token);

    graph.traverseComponents();

    for(int i = 0; i < tokens.size(); i++) {
        token = tokens[i];
        if(graph.nodes.find(token) != graph.nodes.end())
            cout << graph.nodes[token].bestSolution;
        else
            cout << token;

        cout << ((i < tokens.size() - 1) ? " " : "");
    }
    cout << "\n";
    return 0;
}