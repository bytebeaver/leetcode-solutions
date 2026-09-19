class Solution {
public:

    // Each pair stores a character and its frequency.
    // Example: {'e', 2} means character 'e' appears twice.
    typedef pair<char, int> P;


    // Custom comparator for creating a Max Heap.
    // The pair with the highest frequency will have the
    // highest priority and appear at the top of the heap.
    struct lambda {

        bool operator()(P &p1, P &p2)
        {
            // Compare the frequencies stored in second.
            // Using '<' makes the largest frequency come first.
            return p1.second < p2.second;
        }
    };


    string frequencySort(string s) {

        // Create a Max Heap of character-frequency pairs.
        // The comparator ensures the highest frequency
        // remains at the top.
        priority_queue<P, vector<P>, lambda> pq;


        // Hash map stores the frequency of every character.
        // Example: for "tree", e will have frequency 2.
        unordered_map<char, int> mp;


        // Count the frequency of each character.
        // Every time a character appears, increase its count.
        for(char &ch : s)
        {
            mp[ch]++;
        }


        // Insert every character-frequency pair into the heap.
        // The heap automatically arranges pairs according
        // to the custom frequency-based comparator.
        for(auto &it : mp)
        {
            // it.first  = character
            // it.second = frequency
            pq.push({it.first, it.second});
        }


        // This string will store the final sorted answer.
        string result = "";


        // Extract characters from highest to lowest frequency.
        while(!pq.empty())
        {
            // Access the pair with the highest frequency.
            P temp = pq.top();


            // Remove the top pair so the next highest-frequency
            // character can be processed in the next iteration.
            pq.pop();


            // Repeat the character according to its frequency.
            // Example: {'e', 2} produces "ee".
            // string(count, character) creates the repeated string.
            result += string(temp.second, temp.first);
        }


        // Return the string arranged in decreasing frequency.
        return result;
    }
};