#pragma once
#include <condition_variable>
#include <map>
#include <string>

namespace BehaviorTree
{
    class BlackBoard
    {
    private:
        std::map<std::string, std::condition_variable_any> _data;
    public:
        template<typename T>
            void set(const std::string& key, const T& value)
        {
            _data[key] = std::any(value);
        }

        template<typename T>
            T get(const std::string& key)
        {
                auto it = _data.find(key);
                if (it != _data.end)
                    return std::any_cast<T>(it->second);
            return default;
        }
    };
}
