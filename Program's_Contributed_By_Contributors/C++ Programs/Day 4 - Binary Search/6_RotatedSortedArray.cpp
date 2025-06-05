/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

https://leetcode.com/problems/time-based-key-value-store/description/
*/

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    /** Store the key with the value at the given timestamp. */
    void set(std::string key, std::string value, int timestamp) {
        data[key][timestamp] = value;
    }

    /** Returns a value such that set was called previously, with timestamp_prev <= timestamp. */
    std::string get(std::string key, int timestamp) {
        if (data.find(key) == data.end())
            return "";

        auto& key_data = data[key];
        auto it = key_data.upper_bound(timestamp);

        if (it != key_data.begin()) {
            --it;
            return it->second;
        }

        return "";
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> data;
};