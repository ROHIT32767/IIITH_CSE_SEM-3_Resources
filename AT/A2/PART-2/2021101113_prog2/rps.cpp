#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int INT;
map<INT, INT> encoding;
INT total_states = 0;
INT final_index = 0;
map<string, INT> index_of_encodings;
class nodes
{
public:
    char state_type;
    string number;
    string on_rock;
    string on_paper;
    string on_scissors;
};
nodes node[1000];
void pre_order_traversal(tuple<char, INT, INT, INT> T[], INT idx)
{
    INT r1 = -1;
    INT p1 = -1;
    INT s1 = -1;
    string STRING = node[idx].number;
    INT flag_R = 0;
    INT flag_S = 0;
    INT flag_P = 0;
    string R_go = "";
    string S_go = "";
    string P_go = "";
    set<INT> R;
    set<INT> S;
    set<INT> P;
    for (INT i = total_states - 1; i >= 0; i--)
    {
        R_go.push_back('0');
        S_go.push_back('0');
        P_go.push_back('0');
    }
    for (INT i = 0; i < total_states; i++)
    {
        if (STRING[i] == '1')
        {
            char Z = get<0>(T[i]);
            if (Z == 'R')
            {
                r1++;
                flag_R = 1;
                R.insert(i);
            }
            else if (Z == 'S')
            {
                s1++;
                flag_S = 1;
                S.insert(i);
            }
            else if (Z == 'P')
            {
                p1++;
                flag_P = 1;
                P.insert(i);
            }
        }
    }
    INT max_frequency;
    if (r1 > p1)
    {
        max_frequency = r1;
    }
    else
    {
        max_frequency = p1;
    }
    if (s1 > max_frequency)
    {
        max_frequency = s1;
    }
    char ch;
    INT num;
    if (max_frequency == r1)
    {
        ch = 'P';
        num = 1;
    }
    else if (max_frequency == s1)
    {
        ch = 'R';
        num = -1;
    }
    else if (max_frequency == p1)
    {
        ch = 'S';
        num = 2;
    }
    node[idx].state_type = ch;
    index_of_encodings[STRING] = idx + 1;
    INT parent_index = idx;
    char state_character = ch;
    INT flag_for_P = flag_P;
    INT flag_for_R = flag_R;
    INT flag_for_S = flag_S;
    if (flag_for_R)
    {
        set<INT>::iterator it_R;
        for (it_R = R.begin(); it_R != R.end(); it_R++)
        {
            if (ch == 'R')
            {
                INT X = get<1>(T[*it_R]);
                R_go[X - 1] = '1';
            }
            else if (ch == 'S')
            {
                INT X = get<3>(T[*it_R]);
                R_go[X - 1] = '1';
            }
            else if (ch == 'P')
            {
                INT X = get<2>(T[*it_R]);
                R_go[X - 1] = '1';
            }
        }
        if (index_of_encodings[R_go] == 0)
        {
            idx++;
            final_index++;
            index_of_encodings[R_go] = final_index + 1;
            node[parent_index].on_rock = R_go;
            node[final_index].number = R_go;
            pre_order_traversal(T, idx);
        }
        else
        {
            node[parent_index].on_rock = R_go;
        }
    }
    else
    {
        node[parent_index].on_rock = STRING;
    }
    // rock over
    if (flag_for_P)
    {
        set<INT>::iterator it_P;
        for (it_P = P.begin(); it_P != P.end(); it_P++)
        {
            if (ch == 'R')
            {
                INT X = get<1>(T[*it_P]);
                P_go[X - 1] = '1';
            }
            else if (ch == 'S')
            {
                INT X = get<3>(T[*it_P]);
                P_go[X - 1] = '1';
            }
            else if (ch == 'P')
            {
                INT X = get<2>(T[*it_P]);
                P_go[X - 1] = '1';
            }
        }
        if (index_of_encodings[P_go] == 0)
        {
            idx++;
            final_index++;
            index_of_encodings[P_go] = final_index + 1;
            node[parent_index].on_paper = P_go;
            node[final_index].number = P_go;
            pre_order_traversal(T, final_index);
        }
        else
        {
            node[parent_index].on_paper = P_go;
        }
    }
    else
    {
        node[parent_index].on_paper = STRING;
    }
    // paper over
    if (flag_for_S)
    {
        set<INT>::iterator it_S;
        for (it_S = S.begin(); it_S != S.end(); it_S++)
        {
            if (ch == 'R')
            {
                INT X = get<1>(T[*it_S]);
                S_go[X - 1] = '1';
            }
            else if (ch == 'S')
            {
                INT X = get<3>(T[*it_S]);
                S_go[X - 1] = '1';
            }
            else if (ch == 'P')
            {
                INT X = get<2>(T[*it_S]);
                S_go[X - 1] = '1';
            }
        }
        if (index_of_encodings[S_go] == 0)
        {
            idx++;
            final_index++;
            index_of_encodings[S_go] = final_index + 1;
            node[parent_index].on_scissors = S_go;
            node[final_index].number = S_go;
            pre_order_traversal(T, final_index);
        }
        else
        {
            node[parent_index].on_scissors = S_go;
        }
    }
    else
    {
        node[parent_index].on_scissors = STRING;
    }
}

int main(void)
{
    INT N;
    cin >> N;
    total_states = N;
    tuple<char, INT, INT, INT> T[N];
    for (INT i = 0; i < N; i++)
    {
        char ch;
        INT r, p, s;
        cin >> ch >> r >> p >> s;
        T[i] = make_tuple(ch, r, p, s);
    }
    string s1 = "";
    for (INT i = total_states - 1; i >= 0; i--)
    {
        s1.push_back('1');
    }
    node[0].number = s1;
    pre_order_traversal(T, 0);
    cout << final_index + 1 << endl;
    for (INT i = 0; i <= final_index; i++)
    {
        cout << node[i].state_type << " " << index_of_encodings[node[i].on_rock] << " " << index_of_encodings[node[i].on_paper] << " " << index_of_encodings[node[i].on_scissors] << endl;
    }
    final_index = 0;
    total_states = 0;
}