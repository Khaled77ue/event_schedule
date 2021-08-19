#include <vector>
#include <bits/shared_ptr.h>

template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    int oldlen = vec.size();
    if(start < 0 || start >= oldlen)
    {
        throw "BadInput";
    }
    if(stop < 0 || start > oldlen)
    {
        throw "BadInput";
    }
    if(step <= 0)
    {
        throw "BadInput";
    }
    if(start >= stop)
    {
        return std::vector<T>();
    }
    int newlen;
    if(stop == -1 || stop >= oldlen)
    {
        newlen = oldlen - start;
    }
    else{
        newlen = stop - start;
    }
    std::vector<T> vec2(newlen);
    for(int i=start;i<stop;i+=step)
    {
        vec2[i] = vec[start+i];
    }
    return vec2;

}


class A {
public:
    A();
    std::vector<std::shared_ptr<int>> values;
    void add(int x)
    {
        std::shared_ptr<int> new_value(new int(x));
        values.push_back(new_value);
    }
};