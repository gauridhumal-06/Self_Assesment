#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
vector<string> M(100);
vector<char> R(4);
vector<char> IR(4);
vector<int> IC(2);
bool C;
int m = 0;
int SI;
ifstream input_file;

void showCPU()
{
    cout << "R :" << R[0] << " " << R[1] << " " << R[2] << " " << R[3] << " "
         << "\n";

    cout << "IR :" << IR[0] << " " << IR[1] << " " << IR[2] << " " << IR[3] << " "
         << "\n";

    cout << "IC :" << IC[0] << " " << IC[1] << "\n";

    cout << "C :" << C << "\n\n";
}

void memory_data()
{

    for (int j = 0; j < M.size(); j++)
    {
        cout << "M[" << j << "] " << M[j] << "\n";
    }
}

void read()
{
    string buffer2 = "";
    // if (!input_file.eof())
    // {

    getline(input_file, buffer2);
    IR[3] = '0';
    int memory = ((IR[2] - '0') * 10) + (IR[3] - '0');

    int N = buffer2.length();
    int trav = (N / 4) + 1;
    int i = 0;
    while (trav--)
    {
        string temp = buffer2.substr(i, 4);
        i += 4;
        M[memory] = temp;
        memory++;
    }
    // }
}

void write()
{
    IR[3] = '0';
    fstream output_file;
    output_file.open("output.txt", ios::app);
    int memory = ((IR[2] - '0') * 10) + (IR[3] - '0');
    for (int i = memory; i < memory + 10; i++)
    {
        output_file << M[i];
    }
    output_file << "\n";
}

void terminate_prog()
{
    fstream output_file;
    output_file.open("output.txt", ios::app);
    output_file << "\n\n";
}

void masterMode(int SI)
{
    switch (SI)
    {
    case 1:
        read();
        break;
    case 2:
        write();
        break;
    case 3:
        terminate_prog();
        break;
    }
}
void incrementIC()
{
    if (IC[1] == 9)
    {
        IC[0]++;
        IC[1] = 0;
    }
    else
    {
        IC[1]++;
    }
}
void init()
{
    M.clear();
    R.clear();
    IR.clear();
    IC.clear();
    M.resize(100, " ");
    R.resize(4, ' ');
    IR.resize(4, ' ');
    IC.resize(2, -1);
    C = false;
    SI = 3;
    m = 0;
}

void executeUserProgram()
{
    // showCPU();
    int n = (IC[0] * 10) + IC[1];
    string instruct = M[n];
    IR[0] = instruct[0];
    IR[1] = instruct[1];
    IR[2] = instruct[2];
    IR[3] = instruct[3];
    incrementIC();

    if (IR[0] == 'G' && IR[1] == 'D')
    {
        SI = 1;
        masterMode(SI);
    }
    else if (IR[0] == 'P' && IR[1] == 'D')
    {

        SI = 2;
        masterMode(SI);
    }
    else if (IR[0] == 'H')
    {

        SI = 3;
        masterMode(SI);
        return;
        // break;
    }
    else if (IR[0] == 'L' && IR[1] == 'R')
    {

        int memory = ((IR[2] - '0') * 10) + (IR[3] - '0');
        string temp = M[memory];
        for (int i = 0; i < 4; i++)
        {
            R[i] = temp[i];
        }
    }
    else if (IR[0] == 'S' && IR[1] == 'R')
    {
        // cout<<IR[0]<<IR[1];
        int ir2 = IR[2] - '0';
        int ir3 = IR[3] - '0';

        int temp = (ir2 * 10) + ir3;
        string value = "";
        for (int i = 0; i < 4; i++)
        {
            value += R[i];
        }
        M[temp] = value;
    }
    else if (IR[0] == 'C' && IR[1] == 'R')
    {
        // cout<<IR[0]<<IR[1];
        int ir2 = IR[2] - '0';
        int ir3 = IR[3] - '0';

        int temp = (ir2 * 10) + ir3;
        string value = M[temp];
        for (int i = 0; i < 4; i++)
        {
            if (value[i] == R[i])
                C = true;

            else
                C = false;
        }
    }
    else if (IR[0] == 'B' && IR[1] == 'T')
    {

        if (C == true)
        {
            IC[0] = IR[2] - '0';
            IC[1] = IR[3] - '0';
        }
    }
    executeUserProgram();
}
void startExecution()
{
    IC[0] = 0;
    IC[1] = 0;
    executeUserProgram();
}

void loadToMemory(string buffer)
{
    if (m == 100)
    {
        cout << "Memory full\n";
        exit(0);
    }
    else
    {
        int N = buffer.length();
        int trav = (N / 4) + 1;
        int i = 0;
        while (trav--)
        {
            string temp = buffer.substr(i, 4);
            i += 4;
            M[m] = temp;
            m++;
        }
    }
}
// ifstream input_file;
int main(int argc, char const *argv[])
{
    input_file.open("input.txt");
    string buffer = "";
    while (!input_file.eof())
    {
        getline(input_file, buffer);
        string temp = buffer.substr(0, 4);
        if (temp == "$AMJ")
        {
            cout << "This is control card\n";
            init();
            continue;
        }
        else if (temp == "$DTA")
        {
            startExecution();
        }
        else if (temp == "$END")
        {
            cout << "Program ended successfully\n";
        }
        else if (temp != "$AMJ" && temp != "$DTA" && temp != "$END")
        {
            loadToMemory(buffer);
            // break;
        }
    }
    memory_data();
    return 0;
}