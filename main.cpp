// (신박하네)공부하자
// https://programmers.cokr/learn/courses/30/lessons/42576/solution_groups?language=cpp
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// char c[29];
// string solution(vector<string> a, vector<string> b) {
//     for(int j = 0; j < 21; j++){
//         c[j] = 0;
//     }
//     for(int i = 0; i < a.size(); i++){
//         for(int j = 0; j < a[i].size(); j++){
//             cout << "a[i][j] : " << a[i][j] << "\n";
//             c[j]^=a[i][j];
//             cout << "c[j] : " << c[j] << "\n";
//         }
//     }
//     for(int i = 0; i < b.size(); i++){
//         for(int j = 0; j < b[i].size(); j++){
//             c[j]^=b[i][j];
//         }
//     }
//     return string(c);
// }

// int main() {
//   vector<string>participant{"mislav", "stanko", "mislav", "ana"};
//   vector<string>completion{"stanko", "ana", "mislav"};
  
//   solution(participant, completion);
//   string a = solution(participant, completion);
//   cout << a << endl;
//   return 0;
// }


// 좀더 생각 전화번호
// char c[20];
// char h[20];
// bool solution(vector<string> phone_book) {
//     bool answer = true;
    
//     for(int i = 0; i < 20; i++) {
//         c[i] = 0;
//     }
//     for(int i = 0; i < 20; i++) {
//        h[i] = 0;
//     }
//     for(int i = 1; i < phone_book.size(); i++) {
//         for(int j = 0; j < phone_book[i].size(); j++) {
//             c[j] ^= phone_book[i][j];

//             if(string(c) == string(h)){
//                 answer = false;
//                 break;
//             }
//             else {
//                 for(int i = 0; i < phone_book[0].size(); i++){
//                     c[i] = phone_book[0][i];
//                 }
//             }
//         }
//     }
    
//     return answer;
// }


// 이건 더러움 신고자
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> err_li;
    vector<pair<string, string>> li;
    unordered_map<string, string> confirm;

    for (string s : report) {
        int pos = s.find(' ');
        string reporter = s.substr(0, pos);
        string err = s.substr(pos + 1);
        if (confirm[s] != s) {
            confirm[s] = s;
            err_li[err] += 1;
            if (err_li[err] != 0) {
                li.push_back({reporter, err});
            }
        }
    }

    for (string end_id : id_list) {
        int count = 0;
        for (pair<string, string> l : li) {
            if (end_id == l.first) {
                for (pair<string, int> i : err_li) {
                    if (i.second >= k) {
                        if (l.second == i.first) {
                            count += 1;
                        }
                    }
                }
            }
        }
        answer.push_back(count);
    }

    return answer;
}

int main() {
    vector<string> id_list = {"con", "ryan"};
    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 2;
    solution(id_list, report, k);
}

// 이건 많이 쉬웠음 로또
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int null = 0;
    for (int lot : lottos) {
        if (lot == 0) {
            null += 1;
        } else {
            for (int win : win_nums) {
                if (lot == win) {
                    count += 1;
                    break;
                }
            }
        }
    }
    answer.push_back(count + null);
    answer.push_back(count);
    for (int i = 0; i < 2; i++) {
        if (answer[i] == 6) {
            answer[i] = 1;
        } else if (answer[i] == 5) {
            answer[i] = 2;
        } else if (answer[i] == 4) {
            answer[i] = 3;
        } else if (answer[i] == 3) {
            answer[i] = 4;
        } else if (answer[i] == 2) {
            answer[i] = 5;
        } else {
            answer[i] = 6;
        }
    }
    return answer;
}

int main() {
  vector<int> lottos = {44, 1, 0, 0, 31, 25};
  vector<int> win_nums = {31, 10, 45, 1, 6, 19};
  solution(lottos, win_nums);

  return 0;
}


// 신규 아이디
// 테스트 조건이 더 이상 뭐가 문제인지 모르겠음
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
        if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_') {
            if (new_id[i] == '.') {
                for (int j = i; j < new_id.size(); j++) {
                    if (new_id[i] != new_id[j]) {
                        answer.push_back(new_id[i]);
                        i = j - 1;
                        break;
                    }
                }
            } else {
                answer.push_back(new_id[i]);
            }
        }
        if (isdigit(new_id[i]) != 0 || isalpha(new_id[i]) != 0) {
            answer.push_back(new_id[i]);
        }
    }
    if (answer[0] == '.') {
        for (int i = 0; i < answer.size(); i++) {
            if (answer[0] != answer[i]) {
                answer.erase(0, i);
                break;
            }
        }
    }
    if (answer.size() > 15) {
        answer.erase(15, new_id.size());
    }
    if (answer[answer.size() - 1] == '.') {
        if (answer.size() == 1) {
            answer.clear();
        }
        for (int j = answer.size() - 2; j > 0; j--) {
            if (answer[answer.size() - 1] != answer[j]) {
                answer.erase(j + 1, answer.size() - 1);
                break;
            }
        }
    }
    if (answer.size() == 0) {
        answer.push_back('a');
    }
    if (answer.size() <= 2) {
        for (int i = answer.size(); i < 3; i++) {
            answer.push_back(answer[answer.size() - 1]);
        }
    }

    return answer;
}

int main() {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    solution(new_id);
}

// isdigit 숫자
// isalpha 알파벳

int main() {
  std::string new_id = {""};
  solution(new_id);

  return 0;
}


// 키패드 누르기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l = 0;
    int r = 0;
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer.push_back('L');
            l = num;
        } else if (num == 3 || num == 6 || num == 9) {
            answer.push_back('R');
            r = num;
        } else if (num == 2 || num == 5 || num == 8 || num == 0) {
            std::cout << num << " : " << l << " : " << r << "\n";

            if ((abs(l - num) == 1 && abs(r - num) == 3) || 
                (abs(l - num) == 3 && abs(r - num) == 1) || 
                (abs(l - num) == 3 && abs(r - num) == 3) || 
                (abs(l - num) == 3 && abs(r - num) == 3)) {
                if (hand == "right") {
                    answer.push_back('R');
                    r = num;
                } else {
                    answer.push_back('L');
                    l = num;
                }
            } else if (abs(l - num) < abs(r - num)) {
                answer.push_back('L');
                l = num;
            } else if (abs(l - num) > abs(r - num)) {
                answer.push_back('R');
                r = num;
            }
        }
    }
    std::cout << answer;
    return answer;
}

int main() {
  vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
  string hand = "right";
  solution(numbers, hand);

  return 0;
}


// k번째수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> com : commands) {
        vector<int> nums;
        if (com[0] == com[1]) {
            answer.push_back(array[com[0] - 1]);
        } else {
            for (int i = com[0] - 1; i < com[1]; i++) {
                nums.push_back(array[i]);
            }
            sort(nums.begin(), nums.end());
            answer.push_back(nums[com[2] - 1]);
        }
    }

    return answer;
}

int main() {
  vector<int> array = {1, 5, 2, 6, 3, 7, 4};
  vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
  solution(array, commands);

  return 0;
}


// 음양 더하기 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < signs.size(); i++) {
        if (signs[i] == true) {
            answer += absolutes[i];
        } else {
            answer -= absolutes[i];
        }
    }

    return answer;
}

int main() {
    vector<int> absolutes = {4,7,12};
    vector<bool> signs = {true,false,true};
    return 0;
}

// 없는수 더하기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for (int num : numbers) {
        answer -= num;
    }
    return answer;
}

int main() {
    vector<int> numbers = {1,2,3,4,6,7,8,0};
    return 0;
}



// 완전탑색
// 테스트케이스가 뭐가 더있는지 모르겠다 그냥 랜덤으로 적었는지만 잘 나왔다 흠.. 어렵군 ㅋㅋ (내가 문제겠지 ㅋㅋ)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> tree = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int one_count = 0;
    int two_count = 0;
    int tree_count = 0;
    int one_vul = 0;
    int two_vul = 0;
    int tree_vul = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[one_count]) {
            one_vul += 1;
        }
        if (answers[i] == two[two_count]) {
            two_vul += 1;
        }
        if (answers[i] == tree[tree_count]) {
            tree_vul += 1;
        }
        if (one_count == one.size() - 1) {
            one_count = 0;
        }
        if (two_count == two.size() - 1) {
            two_count = 0;
        }
        if (tree_count == tree.size() - 1) {
            tree_count = 0;
        }
        one_count += 1;
        two_count += 1;
        tree_count += 1;
    }
    std::cout << "one_vul : " << one_vul << "\n";
    std::cout << "two_vul : " << two_vul << "\n";
    std::cout << "tree_vul : " << tree_vul << "\n";

    if (one_vul > two_vul && one_vul > tree_vul) {
        answer.push_back(1);
    } else if (two_vul > one_vul && two_vul > tree_vul) {
        answer.push_back(2);
    } else if (tree_vul > one_vul && tree_vul > two_vul) {
        answer.push_back(3);
    } else if (one_vul == two_vul && two_vul == tree_vul) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    } else if (one_vul == two_vul) {
        answer.push_back(1);
        answer.push_back(2);
    } else if (two_vul == tree_vul) {
        answer.push_back(2);
        answer.push_back(3);
    } else if (one_vul == tree_vul) {
        answer.push_back(1);
        answer.push_back(3);
    }
    for (int i : answer) {
        std::cout << i;
    }

    return answer;
}

int main() {
  vector<int> answers = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,5};
  solution(answers);
  return 0;
}


// 백준에 있는문제
// 흠 맞는 지는 모름

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    vector<int> w_list;
    unordered_map<int, int> v_w_list;
    int n, k, v, w;
    cin >> n >> k;
    int vul = 0;

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        if (w <= k) {
            if (v_w_list[w] < v || v_w_list[w] == 0) {
                v_w_list[w] = v;
                w_list.push_back(w);
            }
        }
    }

    sort(w_list.begin(), w_list.end());

    for (int i : w_list) {
        int v_vul = v_w_list[i];
        int w_vul = i;
        for (int j = 0; j < w_list.size(); j++) {
            if (i != w_list[j]) {
                w_vul += w_list[j];
                if (k >= w_vul) {
                    v_vul += v_w_list[w_list[j]];
                } else {
                    w_vul -= w_list[j];
                }
                if (vul == 0 || vul < v_vul) {
                    vul = v_vul;
                }
            }
        }
    }

    cout << vul << "\n";

    return 0;
}