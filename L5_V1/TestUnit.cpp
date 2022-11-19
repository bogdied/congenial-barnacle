//union seems to work fine, but symmetrical difference doesn't beacause I hasn't fixed it yet.





#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
    std::vector<int> vec1 {1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    std::vector<int> vec2 {3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 6};

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());


    std::cout << "------------------------------UNION------------------------------\n";

    std::vector<int> set_union;
    for (int i = 0, j = 0; i < vec1.size() && j < vec2.size();){
        if (i == vec1.size()-1){
            if (vec1[i] == vec2[j]){
                set_union.push_back(vec1[i]);
            }
            else {
                set_union.push_back(vec1[i]);
                set_union.push_back(vec2[j]);
            }
            ++j;
            for (; j < vec2.size(); ++j){
                set_union.push_back(vec2[j]);
            }
        }
        else if (j == vec2.size()-1){
            if (vec1[i] == vec2[j]){
                set_union.push_back(vec1[i]);
            }
            else {
                set_union.push_back(vec1[i]);
                set_union.push_back(vec2[j]);
            }
            ++i;
            for (; i < vec1.size(); ++i){
                set_union.push_back(vec1[i]);
            }
        }
        else if (vec1[i] < vec2[j]){
            set_union.push_back(vec1[i]);
            ++i;
        }
        else if (vec2[j] < vec1[i]){
            set_union.push_back(vec2[j]);
            ++j;
        }
        else {
            set_union.push_back(vec1[i]);
            ++i;
            ++j;
        }
    }
    std::cout << set_union.size() << '\n';
    for (int i : set_union){
        std::cout << i << ' ';
    }
    std::cout << "\n\n";



    std::vector<int16_t> v4;
    std::set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(v4));
    std::cout << v4.size() << '\n';
    for (int16_t& i : v4){
        std::cout << i << ' ';
    }
    std::cout << "\n\n";


    std::cout << "------------------------------SYMMETRIC_DIFFERENCE------------------------------\n";

    std::vector<int> symmetric_difference;
    for (int i = 0, j = 0; i < vec1.size() && j < vec2.size();) {
        if (vec1[i] == vec2[j]){
            vec1.erase(vec1.begin()+i);
            vec2.erase(vec2.begin()+j);
        }
        if (vec1[i] > vec2[j]){
            j++;
        }
        else if (vec1[i] < vec2[j]){
            ++i;
        }
    }

    for (int i = 0, j = 0; i < vec1.size() && j < vec2.size();){
        if (vec1[i] == vec2[j]){
                set_union.push_back(vec1[i]);
            }
            else {
                set_union.push_back(vec1[i]);
                set_union.push_back(vec2[j]);
            }
            ++j;
            for (; j < vec2.size(); ++j){
                set_union.push_back(vec2[j]);
            }
        }
        else if (j == vec2.size()-1){
            if (vec1[i] == vec2[j]){
                set_union.push_back(vec1[i]);
            }
            else {
                set_union.push_back(vec1[i]);
                set_union.push_back(vec2[j]);
            }
            ++i;
            for (; i < vec1.size(); ++i){
                set_union.push_back(vec1[i]);
            }
        }
        else if (vec1[i] < vec2[j]){
            symmetric_difference.push_back(vec1[i]);
            ++i;
        }
        else if (vec2[j] < vec1[i]){
            symmetric_difference.push_back(vec2[j]);
            ++j;
        }
        else {
            symmetric_difference.push_back(vec1[i]);
            ++i;
            ++j;
        }
    }

    std::cout << symmetric_difference.size() << '\n';
    for (int& i : symmetric_difference){
        std::cout << i << ' ';
    }

    std::cout << "\n\n";

    std::vector<int16_t> v5;
    std::set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(v5));
    std::cout << v5.size() << '\n';
    for (int16_t& i : v5){
        std::cout << i << ' ';
    }
}
