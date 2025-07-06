#include <bits/stdc++.h>
using namespace std;

map<string, int> cityToNum;
map<int, string> numToCity;
vector<string> paths;
vector<int> pathWeight;

string source;
string destination;

class Graph {
    int vertices;
    vector<pair<int, int>> *adj;

  public:
    Graph(int v) {
        vertices = v;
        adj = new vector<pair<int, int>>[v];
    }

    void addEdge(int src, int dest, int weight);
    void printGraph();
    void solve();
    void solveUtil(int v, string &path, int &weight);
};

void Graph::addEdge(int src, int dest, int weight) {
    adj[src].push_back(make_pair(dest, weight));
    // adj[dest].push_back(make_pair(src,weight));
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout << "Source Node is : " << numToCity[i] << endl;
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "\tNext Node : " << numToCity[adj[i][j].first]
                 << "   Weight of the path :  " << adj[i][j].second << endl;
        }
    }
}

void Graph::solveUtil(int v, string &path, int &weight) {

    // cout<<"Inside SolveUtil Node is : "<<numToCity[v]<<endl;

    // path += " " + numToCity[v];

    // cout<<path <<  "   " << weight<<endl;

    if (numToCity[v] == destination) {
        paths.push_back(path);
        pathWeight.push_back(weight);
        return;
    }

    for (int j = 0; j < adj[v].size(); j++) {
        // cout<<"\tNext Node : "<<numToCity[adj[v][j].first]<<"   Weight of the
        // path :  "<<adj[v][j].second<<endl;
        weight += adj[v][j].second;
        int t = adj[v][j].first;
        path += " " + numToCity[t];

        solveUtil(adj[v][j].first, path, weight);

        weight -= adj[v][j].second;
        int pl = path.length();
        int s1 = numToCity[t].length();
        path = path.substr(0, pl - s1 - 1);
    }
}

void Graph::solve() {

    // cout<<"Source Node is : "<<numToCity[0]<<endl;

    string path = numToCity[0];
    int weight = 0;

    for (int j = 0; j < adj[0].size(); j++) {
        // cout<<"\tNext Node : "<<numToCity[adj[0][j].first]<<"   Weight of the
        // path :  "<<adj[0][j].second<<endl; bool res = false;
        weight = adj[0][j].second;
        path = numToCity[0];
        int v = adj[0][j].first;
        path += " " + numToCity[v];

        solveUtil(adj[0][j].first, path, weight);

        int pl = path.length();
        int s1 = numToCity[v].length();
        path = path.substr(0, pl - s1 - 1);
    }
}

bool testCond(pair<string, int> p1, pair<string, int> p2) {

    if (p1.second < p2.second)
        return true;
    else if (p1.second > p2.second)
        return false;
    else { // if equal
        if (p1.first.length() < p2.first.length())
            return true;
    }

    return false;
}

int main() {

    int cost[] = {10000, 4000, 5000, 6000};
    string city1[] = {"Bengaluru", "Bengaluru", "Chennai", "Chennai"};
    string city2[] = {"Coimbatore", "Chennai", "Coimbatore", "Coimbatore"};

    /*
        // testcase2

    int cost[] = {10000,4000,4000};
    string city1[] = {"Bengaluru","Bengaluru","Chennai"};
    string city2[] = {"Coimbatore","Chennai","Coimbatore"};

    */

    int n = 4;
    int idx = 0;

    int src;
    int dest;

    source = "Bengaluru";
    destination = "Coimbatore";

    Graph g(n);

    for (int i = 0; i < n; i++) {

        if (cityToNum.find(city1[i]) == cityToNum.end()) {
            cityToNum.insert(make_pair(city1[i], idx));
            src = idx;
            numToCity.insert(make_pair(idx, city1[i]));
            idx++;
        } else {
            src = cityToNum[city1[i]];
        }

        if (cityToNum.find(city2[i]) == cityToNum.end()) {
            cityToNum.insert(make_pair(city2[i], idx));
            dest = idx;
            numToCity.insert(make_pair(idx, city2[i]));
            idx++;
        } else {
            dest = cityToNum[city2[i]];
        }

        // cout<<src<<"  "<<dest<<endl;

        g.addEdge(src, dest, cost[i]);
    }

    g.solve();

    /*    cout<<paths.size()<<endl;
        cout<<pathWeight.size()<<endl;*/

    vector<pair<string, int>> ansVect;

    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << " " << pathWeight[i] << endl;
        ansVect.push_back(make_pair(paths[i], pathWeight[i]));
    }

    cout << endl;

    sort(ansVect.begin(), ansVect.end(), testCond);

    for (int i = 0; i < ansVect.size(); i++) {
        cout << ansVect[i].first << "  " << ansVect[i].second << endl;
    }
}
