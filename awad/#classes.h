#ifndef CLASSES_H
#define CLASSES_H
#include<bits\stdc++.h>
#include <QMessageBox>

using namespace std ;
class Memory {
public:

    vector<string> memory;
    map<string, int> mp;

    void gen() {
        vector<string> v {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
        vector<string> ans;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                string s;
                s += v[i];
                s += v[j];
                ans.push_back(s);
            }
        }
        for (int i = 0; i < ans.size(); ++i) {
            mp[ans[i]] = i;
        }
    }

    Memory() : memory(256, "00") {}
    void clear() {
        fill(memory.begin(), memory.end(), 0);
    }

    string read(string address) {
        if (mp[address] >= 0 && mp[address] < memory.size())
            return memory[mp[address]];
        return "00";
    }

    void write(string address, string data) {
        if (mp[address] >= 0 && mp[address] < memory.size())
            memory[mp[address]] = data;
    }
};

class Register {
public:
    map<char, int> mp;
    vector<string> registers;

    void gen() {
        vector<char> v {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        for (int i = 0; i < v.size(); ++i) {
            mp[v[i]] = i;
        }
    }

    Register() : registers(16, "00") {}
    void clear() {
        fill(registers.begin(), registers.end(), 0);
    }

    string read(char reg) {
        if (mp[reg] >= 0 && mp[reg] < registers.size())
            return registers[mp[reg]];
        return "00";
    }

    void write(char reg, string value) {
        if (mp[reg] >= 0 && mp[reg] < registers.size())
            registers[mp[reg]] = value;
    }
};

class ALU {
public:
    int hexToDecimal(string hex) {
        int decimalValue;
        stringstream ss;
        ss << std::hex << hex;
        ss >> decimalValue;
        return decimalValue;
    }

    string hexToBinary(string hex) {
        int decimalValue = hexToDecimal(hex);
        bitset<8> binary(decimalValue);
        return binary.to_string();
    }


    string binaryToHex(string binary) {
        int decimalValue = bitset<32>(binary).to_ulong();
        stringstream ss;
        ss << hex << decimalValue;
        return ss.str();
    }

    string decimalToHex(int decimal) {
        stringstream ss;
        ss << hex << decimal;
        return ss.str();
    }

    string add(string a, string b) {
        int temp = hexToDecimal(a) + hexToDecimal(b);
        return decimalToHex(temp);
    }

    void parseFloat(const string& hex, int& sign, int& exponent, int& mantissa) {
        int value = hexToDecimal(hex);
        sign = (value & 0x80) >> 7;
        exponent = (value & 0x70) >> 4;
        mantissa = value & 0x0F;
    }


    string floatToHex(int sign, int exponent, int mantissa) {
        int value = (sign << 7) | (exponent << 4) | mantissa;
        return decimalToHex(value);
    }

    string addFloat(const string& a, const string& b) {
        int signA, exponentA, mantissaA;
        int signB, exponentB, mantissaB;

        parseFloat(a, signA, exponentA, mantissaA);
        parseFloat(b, signB, exponentB, mantissaB);


        if (exponentA > exponentB) {
            int shift = exponentA - exponentB;
            mantissaB >>= shift;
            exponentB = exponentA;
        } else if (exponentB > exponentA) {
            int shift = exponentB - exponentA;
            mantissaA >>= shift;
            exponentA = exponentB;
        }


        int resultMantissa;
        int resultExponent = exponentA;
        int resultSign;

        if (signA == signB) {
            resultMantissa = mantissaA + mantissaB;
            resultSign = signA;
        } else {
            if (mantissaA >= mantissaB) {
                resultMantissa = mantissaA - mantissaB;
                resultSign = signA;
            } else {
                resultMantissa = mantissaB - mantissaA;
                resultSign = signB;
            }
        }


        if (resultMantissa >= 16) {
            resultMantissa >>= 1;
            resultExponent += 1;
        }


        if (resultExponent > 7) {

            resultExponent = 7;
            resultMantissa = 0;
        } else if (resultExponent < 0) {

            resultExponent = 0;
            resultMantissa = 0;
        }

        return floatToHex(resultSign, resultExponent, resultMantissa);
    }
    string bitwiseOR( string s,  string t) {
        string res;
        for (size_t i = 0; i < s.size(); ++i) {
            res += (s[i] == '1' || t[i] == '1') ? '1' : '0';
        }
        return res;
    }

    string bitwiseXOR( string s,  string t) {
        string res;
        for (size_t i = 0; i < s.size(); ++i) {
            res += (s[i] != t[i]) ? '1' : '0';
        }
        return res;
    }

    string bitwiseAND( string s,  string t) {
        string res;
        for (size_t i = 0; i < s.size(); ++i) {
            res += (s[i] == '1' && t[i] == '1') ? '1' : '0';
        }
        return res;
    }


};

class ControlUnit {
public:
    ControlUnit() : programCounter(0) {
        reg.gen();
        memory.gen();
    }


    void loadProgramFromFile() {
        cout << "Enter the name of the file: " << endl;
        string fileName;
        cin >> fileName;

        ifstream file(fileName);
        if (!file) {
            cout << "Error opening file: " << fileName << endl;
            return;
        }

        string instr;
        while (file >> instr) {
            instructions.push_back(instr);
        }
        file.close();
    }

    void loadProgram(const vector<string>& program) {
        instructions = program;
    }

    void printRegisters() {
        cout << "Registers:\n";
        vector<char> v {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        for (int i = 0; i < reg.registers.size(); i++) {
            cout << "Register[" << i << "]: " << reg.read(v[i]) << "\n";
        }
    }

    void printMemory() {
        cout << "Memory:\n";
        vector<string> v;
        for (int i = 0; i <= 255; i++) {
            v.push_back((i < 16 ? "0" : "") + to_string(i));
        }
        for (int i = 0; i < memory.memory.size(); i++) {
            cout << "Memory[" << v[i] << "]: " << memory.read(v[i]) << "\n";
        }
    }

    void executeNext() {
        if (programCounter >= instructions.size()) {
            cout << "Program has ended.\n";
            return;
        }

        string instr = instructions[programCounter++];
        int opcode = instr[0] - '0';

        switch (opcode) {
        case 1:
            executeLoadToRegister(instr);
            break;
        case 2:
            executecopyToregister(instr);
            break;
        case 3:
            executeLoadToMemory(instr);
            break;
        case 4:
            executeCCopyRegToReg(instr);
            break;
        case 5:
            executeIntegerAdd(instr);
            break;
        case 6:
            executeFloatAdd(instr);
            break;
        case 7:
            executeOR(instr);
            break;
        case 8:
            executeAND(instr);
            break;
        case 9:
            executeXOR(instr);
            break;
        case 17:
            Rotate(instr);
            break;
        case 18:
            executeconditional_jumb(instr);
            break;
        case 20:
            executeconditional_jumb_D(instr);
            break;
        // case 19:
        //     halt();
        //     break;
        default:
            cout << "Unknown opcode: " << opcode << "\n";
            break;
        }
    }


    Memory memory;
    Register reg;
    ALU alu;
    int programCounter;
    vector<string> instructions;
    void reset() {
        memory.clear();
        reg.clear();
        instructions.clear();
        programCounter = 0;
    }

    map<string, int> mp;

    void gen() {
        vector<string> v {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
        vector<string> ans;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                string s;
                s += v[i];
                s += v[j];
                ans.push_back(s);
            }
        }
        for (int i = 0; i < ans.size(); ++i) {
            mp[ans[i]] = i;
        }
    }

    void executeLoadToRegister( string instr) {
        char R = instr[1];
        string XY = instr.substr(2, 2);
        reg.write(R, memory.read(XY));
        cout << "Loaded memory[" << XY << "] to register " << R << ": " << reg.read(R) << "\n";
    }
    void executecopyToregister( string instr) {
        char R = instr[1];
        char S = instr[2];
        char T = instr[3];
        string XY = instr.substr(2, 2);
        reg.write(R, XY);
        cout << "Loaded memory cell bits [" << XY << "] to register " << R << "\n";
    }

    void executeLoadToMemory( string instr) {
        char R = instr[1];
        string XY = instr.substr(2, 2);
        memory.write(XY, reg.read(R));
        string temp = "";
        temp +=R;
        cout << "Loaded register[" << R << "] to memory " << XY << ": " << memory.read(temp) << "\n";
    }
    void executeCCopyRegToReg( string instr) {
        char R = instr[2];
        char x = instr[3];
        reg.write(x, reg.read(R));

        cout << "Copied register[" << R << "] to register " << x << "\n";
    }

    void executeIntegerAdd(const string& instr) {
        char R = instr[1];
        string x = reg.read(instr[2]);
        string y = reg.read(instr[3]);
        string result = alu.add(x, y);
        reg.write(R, result);
        cout << "Added register " << instr[2] << " and " << instr[3] << ", stored in " << R << ": " << result << "\n";
    }

    void executeFloatAdd(const string& instr) {
        char R = instr[1];
        string x = reg.read(instr[2]);
        string y = reg.read(instr[3]);
        string result = alu.addFloat(x, y);
        reg.write(R, result);
        cout << "Added register " << instr[2] << " and " << instr[3] << ", stored in " << R << ": " << result << "\n";
    }


    void executeOR(string instr) {
        char R = instr[1];
        string x = reg.read(instr[2]);
        string y = reg.read(instr[3]);
        string s = alu.hexToBinary(x);
        string t = alu.hexToBinary(y);
        string res = alu.bitwiseOR(s, t);
        string ans = alu.binaryToHex(res);
        reg.write(R, ans);
        cout << "Applied Operation OR on Register " << instr[2] << " and Register " << instr[3] << ", and stored in Register " << R << ": " << ans << "\n";
    }

    void executeXOR( string instr) {
        char R = instr[1];
        string x = reg.read(instr[2]);
        string y = reg.read(instr[3]);
        string s = alu.hexToBinary(x);
        string t = alu.hexToBinary(y);
        string res = alu.bitwiseXOR(s, t);
        string ans = alu.binaryToHex(res);
        reg.write(R, ans);
        cout << "Applied Operation XOR on Register " << instr[2] << " and Register " << instr[3] << ", and stored in Register " << R << ": " << ans << "\n";
    }

    void executeAND( string instr) {
        char R = instr[1];
        string x = reg.read(instr[2]);
        string y = reg.read(instr[3]);
        string s = alu.hexToBinary(x);
        string t = alu.hexToBinary(y);
        string res = alu.bitwiseAND(s, t);
        string ans = alu.binaryToHex(res);
        reg.write(R, ans);
        cout << "Applied Operation AND on Register " << instr[2] << " and Register " << instr[3] << ", and stored in Register " << R << ": " << ans << "\n";
    }
    string rotateRight(string binary, int x) {
        int n = binary.length();
        x = x % n;
        return binary.substr(n - x) + binary.substr(0, n - x);
    }

    void Rotate(string instr) {
        char R = instr[1];
        int x = instr[3] - '0';
        string binary = alu.hexToBinary(reg.read(R));

        string rotatedBinary = rotateRight(binary, x);

        reg.write(R, alu.binaryToHex(rotatedBinary));
        cout << "Rotated Register " << R << " By " << x << "X: " << reg.read(R)<< "\n";
    }

    void executeconditional_jumb(string instr)
    {

        char R = instr[1];
        string xy = instr.substr(2,2);
        if (reg.read(R) == reg.read('0'))
        {
            programCounter = mp[xy];

        }
    }
    void executeconditional_jumb_D(string instr)
    {

        char R = instr[1];
        string xy = instr.substr(2,2);
        if (reg.read(R) > reg.read('0'))
        {
            programCounter = mp[xy];
        }
    }



};
#endif // CLASSES_H
