class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void helper(int curr_node, vector<vector<int>> &graph)
    {
        int n = graph.size();
        temp.push_back(curr_node);
        if (curr_node == n - 1)
        {
            ans.push_back(temp);
        }
        else
        {
            for (int x : graph[curr_node])
            {
                helper(x, graph);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        helper(0, graph);
        return ans;
    }
};