#include "ReadWriter.cpp"
#include <algorithm>

//ћожно добавл€ть любые методы дл€ решени€ задачи.

bool Compare(Node* n1, Node* n2)
{
    if (n1->name < n2->name)
    {
        return true;
    }
    return false;
}

void dfs(Node& n, std::vector<Node>& graph, std::vector<std::string>& result) {
    if (n.visited)
    {
        return;
    }
    result.push_back(n.name);
    n.visited = true;
    std::vector<Node*> brr;
    for (Node* neighbour : n.neighbours)
    {
        brr.push_back(neighbour);
    }
    sort(brr.begin(), brr.end(), Compare);
    for (Node* neighbour : brr)
        dfs(*neighbour, graph, result);
}

//«адача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node>& graph, int start, std::vector<std::string>& result)
{
    dfs(graph[start], graph, result);
}

int main() {
    std::vector<Node> graph;
    std::vector<std::string> result;
    int start;

    ReadWriter rw;
    rw.readGraph(graph, start);
    solve(graph, start, result);
    rw.writeAnswer(result);
    return 0;
}
