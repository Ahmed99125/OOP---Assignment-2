//
// Created by at991 on 11/13/2023.
//

#include "Instructions.h"

string toBinary(int num) {
    string result = "";
    while(num > 0) {
        int carry = num % 2;
        num /= 2;
        result = to_string(carry) + result;
    }
    return result;
}

string addBinaryStrings(const string& binary1, const string& binary2) {
    // Make sure both strings have the same length by adding leading zeros
    size_t maxLength = max(binary1.length(), binary2.length());
    string paddedBinary1(maxLength - binary1.length(), '0');
    string paddedBinary2(maxLength - binary2.length(), '0');
    paddedBinary1 += binary1;
    paddedBinary2 += binary2;

    string result;
    int carry = 0;

    // Iterate through the strings from right to left
    for (int i = maxLength - 1; i >= 0; --i) {
        int bit1 = paddedBinary1[i] - '0';
        int bit2 = paddedBinary2[i] - '0';

        // Sum the bits and the carry
        int sum = bit1 + bit2 + carry;

        // Calculate the current bit in the result
        result += (sum % 2) + '0';

        // Update the carry for the next iteration
        carry = sum / 2;
    }

    // If there's a carry left, add it to the result
    if (carry != 0) {
        result += (carry + '0');
    }

    // Reverse the result string to get the correct order
    reverse(result.begin(), result.end());

    // Convert the binary sum to decimal
    int decimalSum = stoi(result, nullptr, 2);

    // Convert the decimal sum to string for consistency
    return to_string(decimalSum);
}

void Instructions::Instruction1(string instruction){
    // convert the hex string to int
    int memoryAddress = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    // put the data from the memory to the register
     SetRegister(registerAddress, getMemory(memoryAddress));
}

void Instructions::Instruction2(string instruction) {
    // convert the hex string to int
    int value = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    // put the data from the memory to the register
    stringstream hexNum;
    hexNum << hex << stoi(to_string(value));
    SetRegister(registerAddress, hexNum.str());
}

void Instructions::Instruction3(string instruction) {
    // convert the hex string to int
    int memoryAddress = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');

    // if memmory address is 0 print to screen else save it in memory
    if (memoryAddress > 0) {
        setMemory(memoryAddress, GetRegister(registerAddress));
    }
    else {
        screen += GetRegister(registerAddress) + "\n";
        PrintScreen();
    }
}

void Instructions::Instruction4(string instruction) {
    // convert the hex string to int
    int firstRegister = (instruction[2] >= 'A') ? (instruction[2] - 'A' + 10) : (instruction[2] - '0');
    // convert the hex char to string
    int secondAddress =  (instruction[3] >= 'A') ? (instruction[3] - 'A' + 10) : (instruction[3] - '0');

    // move the value of the first register to the second register
    SetRegister(secondAddress, GetRegister(firstRegister));
}

void Instructions::Instruction5(string instruction) {
    // convert the hex string to int
    int firstRegister = (instruction[2] >= 'A') ? (instruction[2] - 'A' + 10) : (instruction[2] - '0');
    // convert the hex char to string
    int secondRegister =  (instruction[3] >= 'A') ? (instruction[3] - 'A' + 10) : (instruction[3] - '0');

    int thirdRegister = (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');

    string registerVal1 = GetRegister(firstRegister), registerVal2 = GetRegister(secondRegister);
    int num1 = 0, num2 = 0, power = 1;

    for (int i = registerVal1.size()-1; i >= 0; i--) {
        int digit = (registerVal1[i] >= 'A') ? (registerVal1[i] - 'A' + 10) : (registerVal1[i] - '0');
        digit *= power;
        power *= 16;
        num1 += digit;
    }

    power = 1;

    for (int i = registerVal2.size()-1; i >= 0; i--) {
        int digit = (registerVal2[i] >= 'A') ? (registerVal2[i] - 'A' + 10) : (registerVal2[i] - '0');
        digit *= power;
        power *= 16;
        num2 += digit;
    }

    string num1Binary = toBinary(num1);
    string num2Binary = toBinary(num2);
    string sum = addBinaryStrings(num1Binary, num2Binary);
    stringstream hexSum;
    hexSum << hex << stoi(sum);
    SetRegister(thirdRegister, hexSum.str()) ;
}

int Instructions::InstructionB(string instruction, int prCounter) {
    // convert the hex string to int
    int firstRegister = 0;
    // convert the hex char to string
    int secondRegister =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    if(GetRegister(firstRegister) == GetRegister(secondRegister)) {
        return stoul(instruction.substr(2,2), 0, 16);
    }
    return prCounter;
}

void Instructions::InstructionC(string instruction) {
    if(instruction == "C000") {
        PrintScreen();
        exit(0);
    }
}

void Instructions::PrintScreen() {
    cout << screen << endl;
}

void Instructions::ClearScreen() {
    screen = "Screen:\n";
}