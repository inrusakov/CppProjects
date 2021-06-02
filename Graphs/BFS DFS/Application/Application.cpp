#include "ReadWriter.cpp"
#include <algorithm>
#include <queue>
#include <string>

//ћожно добавл€ть любые методы дл€ решени€ задачи.
bool Compare(Node* n1, Node* n2)
{
	if (n1->name < n2->name)
	{
		return true;
	}
	return false;
}

//«адача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node>& graph, int start, std::vector<std::string>& result)
{
	std::queue<Node*> queue;
	std::vector<Node*> current;
	graph[start].visited = true;
	queue.push(&graph[start]);
	while (!queue.empty())
	{
		while (!queue.empty())
		{
			current.push_back(queue.front());
			queue.pop();
		}
		std::sort(current.begin(), current.end(), Compare);
		for (int i = 0; i < current.size(); i++)
		{
			result.push_back(current[i]->name);
			for (int j = 0; j < current[i]->neighbours.size(); j++)
			{
				if (!current[i]->neighbours[j]->visited)
				{
					queue.push(current[i]->neighbours[j]);
					current[i]->neighbours[j]->visited = true;
				}
			}
		}
		current.clear();
	}
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