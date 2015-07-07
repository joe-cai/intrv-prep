#Simplify Path
The essence of the solutions to this problem is using the backslash as the delimiter. Another short and concise solution uses the C++ function `getline((stringstream)path, name, '/')` which is pretty much the same as the solution below. It is not hard as long as you had taken care of the edge cases properly.
```C++
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        string name;

        path.push_back('/'); // eliminate edge cases without rear backslash
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') { // delimiter
                if (name.size() == 0) continue; // handling edge cases
                else if (name == ".." && dir.size() > 0) dir.pop_back();
                else if (name != ".." && name != ".") dir.push_back(name);
                name.clear();
            } else
                name.push_back(path[i]);
        }
        if (dir.size() == 0) return "/"; // edge case

        string sol;
        for (int i = 0; i < dir.size(); i++)
            sol += "/" + dir[i];
        return sol;
    }
};
```
