#include <iostream>
#include <fstream>
#include <string>

#include "json.hpp"
using json = nlohmann::json;

using namespace std;

int main(int argc, char **argv)
{

    std::ifstream f(argv[1]);
    json data = json::parse(f);
    // cout << "hello" << endl;

    // cout << data.dump(2) << endl;

    // accessing the elements from the json file
    // cout << data["metadata"]["arraySize"] << endl;

    // iterating through a for loop and accessing all of its elements
    //      for (auto it = data.begin(); it != data.end(); it++)
    //  {
    //     if (unsigned i; it[i].value() > it[i+1].value()){
    //     std::cout << "key: " << it.key() << " : " << it.value() << std::endl;
    //     }
    //  }
    json bob; // create the bob JSON object
    int num = 0;

    for (auto it = data.begin(); it != data.end(); it++)  // parse through data
    {
        // cout << it.key() << endl;
        //  cout << data[it.key()] << endl;
        //  cout << data[it.key()] << endl;
        //  cout << "hello" << endl;

        if (it.key() == "metadata")
        {
            continue;
        }

        int arraySizeVar = data["metadata"]["numOps"]; 
        int count = 0;

        for (int i = 0; i < arraySizeVar - 1; i++)
        {

            // cout << data[it.key()][i] << endl;

            if (it.key("key") == "operation"){
                if data[it.key()] == "Insert"
                {
                    count = count + 1;
                    bob[it.key()]["key"] = {data[it.key()]};
                    bob[it.key()]["operation"] = {data[it.key()]};
                    //cout << data[it.key()][i] << "  " << data[it.key()][i + 1] << endl;
                }
            }

        if (count > 0){
            bob[it.key()][to_string(count)] = data[it.key()];
            num++;
        }
    }
    
    // metadata, field = value
    bob["metadata"]["numOps"] = data["metadata"]["arraySize"];

    cout << bob.dump(2) << endl;
}
