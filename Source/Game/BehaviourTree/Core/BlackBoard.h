#pragma once

#include <map>
#include <string>
#include <any>

namespace BehaviourTree
{
    class BlackBoard
    {
    private:
        std::map<std::string, std::any> _data;
    public:
        template<typename T>
            void set(const std::string& key, const T& value)
        {
            _data[key] = std::any(value);
        }

        template<typename T>
            T get(const std::string& key, const T& defaultValue)
        {
                auto it = _data.find(key);
                if (it != _data.end())
                    return std::any_cast<T>(it->second);
            return defaultValue;
        }
    };
}
