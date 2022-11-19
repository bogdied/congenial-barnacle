#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<int>& vec);
void get_size_and_elements(std::vector<int>& vec);
void print_size_and_elements(std::vector<int>& vec);
void set_difference(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);
void set_intersection(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);
void set_union(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);


int main() {

    std::vector<int> first;
    std::vector<int> second;

    get_size_and_elements(first);
    get_size_and_elements(second);

    sort(first);
    sort(second);

//    std::vector<int> f_s_difference;
//    set_difference(first, second, f_s_difference);
//    print_size_and_elements(f_s_difference);
//
//    std::vector<int> s_f_difference;
//    set_difference(second, first, f_s_difference);
//    print_size_and_elements(f_s_difference);
//
//    std::vector<int> intersection;
//    set_intersection(first, second, intersection);
//    print_size_and_elements(intersection);

    std::vector<int> Union;
    set_union(first, second, Union);
    print_size_and_elements(Union);

    std::vector<int> stl_union;
    std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(stl_union));
    print_size_and_elements(stl_union);

//    std::cout << (Union == stl_union) ? "YES" : "NO";


//    print_size_and_elements(first);
//    print_size_and_elements(second);
}

void set_union(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    int i = 0, j = 0;
    while (true){

        if (i == first.size()-1){
            if (first[i] == second[j]){
                output.push_back(first[i]);
                ++j;
                while (j < second.size()){
                    output.push_back(second[j]);
                    ++j;
                }
                break;
            }
            else {
                output.push_back(first[i]);
                output.push_back(second[j]);
                ++i;
                ++j;
                while (j < second.size()){
                    output.push_back(second[j]);
                    ++j;
                }
                break;
            }
        }

        if (j == second.size()-1){
            if (first[i] == second[j]){
                output.push_back(first[i]);
                ++i;
                while (i < first.size()){
                    output.push_back(first[i]);
                    ++i;
                }
                break;
            }
            else {
                output.push_back(first[i]);
                output.push_back(second[j]);
                ++i;
                ++j;
                while (i < first.size()){
                    output.push_back(first[i]);
                    ++i;
                }
                break;
            }
        }

        else if (first[i] > second[j]){
            output.push_back(second[j]);
            ++j;
        }
        else if (second[j] > first[i]){
            output.push_back(first[i]);
            ++i;
        }
        else {
            output.push_back(first[i]);
            ++i;
            ++j;
        }
    }
}

void set_intersection(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()){
        if (first[i] > second[j])
            ++j;
        else if (second[j] > first[i])
            ++i;
        else {
            output.push_back(first[i]);
            ++i;
            ++j;
        }
    }
}

void set_difference(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    int i = 0, j = 0;
    output = first;
    while (i < output.size() && j < second.size()){
        if (output[i] > second[j])
            ++j;
        else if (second[j] > output[i])
            ++i;
        else {
            output.erase(output.begin()+i);
        }
    }
}

void get_size_and_elements(std::vector<int>& vec){
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i){
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
}

void print_size_and_elements(std::vector<int>& vec){
    std::cout << vec.size() << '\n';
    for (int i : vec){
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
}

void sort(std::vector<int>& vec) {
    for (int s = static_cast<int>(vec.size()) / 2; s > 0; s /= 2) {
        for (int i = s; i < vec.size(); ++i) {
            for (int j = i - s; j >= 0 && vec[j] > vec[j + s]; j -= s) {
                int temp = vec[j];
                vec[j] = vec[j + s];
                vec[j + s] = temp;
            }
        }
    }
}
