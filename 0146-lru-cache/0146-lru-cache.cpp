// class LRUCache {
// public:
//     vector< pair<int, int>> cache;
//     int n;
//     LRUCache(int capacity) {
//          n = capacity;
//     }
    
//     int get(int key) {
        
//         for(int i=0; i<cache.size() ; i++)
//         {
//             if( cache[i].first == key)
//             {
//                 int val = cache[i].second;

//                 pair<int, int> temp = cache[i];
//                 cache.erase( cache.begin() + i);
//                 cache.push_back(temp );

//                 return val;
//             }
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
        
//          for(int i=0; i<cache.size() ; i++)
//          {
//             if( cache[i].first == key)
//             {
//                 cache[i].second = value;
//                 pair<int, int> temp = cache[i];
//                 cache.erase( cache.begin() + i);
//                 cache.push_back(temp );

//                 return ;
//             }
//          }

//          if( cache.size() == n)
//          {
//             //get rid of least recently used
//               cache.erase( cache.begin());
//          }

//          cache.push_back( {key, value});
//      }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




class LRUCache {
public:
    
    list<int> dll; //key

    map<int, pair< list<int> :: iterator, int>>mp; // list<int> :: iterator gives address of the node in Doubly linked list;


    int n ;

    LRUCache(int capacity) {
         n = capacity;
    }

    void makeRecentlyUsed( int key )
    {
        //pehle to ham erse krenge  ....is key ka address mujhe map se milega
        dll.erase( mp[key].first );
        
        //now make it most recently used bu adding it to front
        dll.push_front(key);

        mp[key].first = dll.begin(); //since the key's position is change to front of the list its address must also be changed and we have to update that in map
    }
    
    int get(int key) {
        
       if( mp.find(key) ==mp.end()) //if that key does not exist in our cache
       return -1;

       //else if it is presnt ..i need to move it to front
       makeRecentlyUsed(key);

       return mp[key].second; //i have to return the value and that is in map
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)  != mp.end())
        {
            //upate its value and make it most recently used
            mp[key].second = value;

            makeRecentlyUsed( key );

        }

        //if it is not already presnt we have to insert it 
        else
        {
            dll.push_front(key);

            mp[key] = { dll.begin(), value}; //since it is newly inserted at beginning ....its address is given by dll.begin() 

            n--;
        }

        if( n< 0)// we have more nodes than the allowed capacity
        {
            //erase the least recently used and that node will be ata back of list
            int key_to_be_deleted = dll.back();

            //deleting from map firstly
            mp.erase( key_to_be_deleted);

            //deleting from list
            dll.pop_back();

            //since we have deleted we have to update the capacity
            n++;

        }
     }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */