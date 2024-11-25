// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the One's complement
// of the given binary string
string Ones_complement(string data)
{
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0')
			data[i] = '1';
		else
			data[i] = '0';
	}

	return data;
}

// Function to return the checksum value of
// the give string when divided in K size blocks
string checkSum(string data, int block_size)
{
	// Check data size is divisible by block_size
	// Otherwise add '0' front of the data
	int n = data.length();
	if (n % block_size != 0) {
		int pad_size = block_size - (n % block_size);
		for (int i = 0; i < pad_size; i++) {
			data = '0' + data;
		}
	}

	// Binary addition of all blocks with carry
	string result = "";

	// First block of data stored in result variable
	for (int i = 0; i < block_size; i++) {
		result += data[i];
	}

	// Loop to calculate the block
	// wise addition of data
	for (int i = block_size; i < n; i += block_size) {

		// Stores the data of the next bloack
		string next_block = "";

		for (int j = i; j < i + block_size; j++) {
			next_block += data[j];
		}

		// Stores the binary addition of two blocks
		string additions = "";
		int sum = 0, carry = 0;

		// Loop to calculate the binary addition of
		// the current two blocls of k size
		for (int k = block_size - 1; k >= 0; k--) {
			sum += (next_block[k] - '0')
				+ (result[k] - '0');
			carry = sum / 2;
			if (sum == 0) {
				additions = '0' + additions;
				sum = carry;
			}
			else if (sum == 1) {
				additions = '1' + additions;
				sum = carry;
			}
			else if (sum == 2) {
				additions = '0' + additions;
				sum = carry;
			}
			else {
				additions = '1' + additions;
				sum = carry;
			}
		}

		// After binary add of two blocks with carry,
		// if carry is 1 then apply binary addition
		string final = "";

		if (carry == 1) {
			for (int l = additions.length() - 1; l >= 0;
				l--) {
				if (carry == 0) {
					final = additions[l] + final;
				}
				else if (((additions[l] - '0') + carry) % 2
						== 0) {
					final = "0" + final;
					carry = 1;
				}
				else {
					final = "1" + final;
					carry = 0;
				}
			}

			result = final;
		}
		else {
			result = additions;
		}
	}

	// Return One's complements of result value
	// which represents the required checksum value
	return Ones_complement(result);
}

// Function to check if the received message
// is same as the senders message
bool checker(string sent_message,
			string rec_message,
			int block_size)
{

	// Checksum Value of the senders message
	string sender_checksum
		= checkSum(sent_message, block_size);

	// Checksum value for the receivers message
	string receiver_checksum = checkSum(
		rec_message + sender_checksum, block_size);

	// If receivers checksum value is 0
	if (count(receiver_checksum.begin(),
			receiver_checksum.end(), '0')
		== block_size) {
		return true;
	}
	else {
		return false;
	}
}

// Driver Code
int main()
{
	string sent_message
		= "10000101011000111001010011101101";
	string recv_message
		= "10000101011000111001010011101101";
	int block_size = 8;

	if (checker(sent_message,
				recv_message,
				block_size)) {
		cout << "No Error";
	}
	else {
		cout << "Error";
	}

	return 0;
}
