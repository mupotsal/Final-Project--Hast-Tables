// Final Project
// Liberty Mupotsa

#include <iostream>

using namespace std;

#include <iostream>
#include <string>
using namespace std;

class HashTable {
public:
	static const int size = 25; // initial size of hash table is prime to help with collision resolution
	int slots[size]; // list to hold key items
	string data[size]; // list to hold data values 


	//modify the following hashing function so that one can use strings as Keys to data

	int converter(string key) { // another hash function using weighting
		int sum = 0;
		char arr[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		for (int i = 0; i < key.size(); i++) {
			for (int j = 0; j < 26; j++) {				
				if (arr[j] == key[i] ) {
					sum += j+1;
					
				}
			}
		}
		
		
		return  sum;
	}


	int hashfunction(int key) { // implements remainder method
		return (key^2) % size;
	}
	// Computes original hashvalue, and if slot is
	// not empty iterates until empty slot is found // Using linear probing for collision resolution.
	int rehash(int oldhash) {
		return (oldhash + 1) % size;
	}

	// Function that assumes there will eventually be
	// an empty slot unless the key is alread present in the slot
	void put(int key, string val) {
		int hashvalue = hashfunction(key);
		int count = 0;

		if (data[hashvalue] == "") {
			slots[hashvalue] = key;
			data[hashvalue] = val;
		}
		else {
			if (slots[hashvalue] == key) {
				data[hashvalue] = val;
			}
			else {
				int nextslot = rehash(hashvalue);

				while (data[nextslot] != "" && slots[nextslot] != key) {
					nextslot = rehash(nextslot);

					count++;
					if (count > size) {
						cout << "TABLE FULL" << endl;
						return;
					}
				}
				if (data[nextslot] == "") {
					slots[nextslot] = key;
					data[nextslot] = val;
				}
				else {
					data[nextslot] = val;
				}
			}
		}
	}

	void put( string keyys, string val) {

		//That is where we need to do the ,maths to change the string key to an integer value.
		int key = converter(keyys);
		int hashvalue = hashfunction(key);
		int count = 0;

		if (data[hashvalue] == "") {
			slots[hashvalue] = key;
			data[hashvalue] = val;
		}
		else {
			if (slots[hashvalue] == key) {
				data[hashvalue] = val;
			}
			else {
				int nextslot = rehash(hashvalue);

				while (data[nextslot] != "" && slots[nextslot] != key) {
					nextslot = rehash(nextslot);

					count++;
					if (count > size) {
						cout << "TABLE FULL" << endl;
						return;
					}
				}
				if (data[nextslot] == "") {
					slots[nextslot] = key;
					data[nextslot] = val;
				}
				else {
					data[nextslot] = val;
				}
			}
		}
	}

	// computes the initial hash value
	// if value is not in the initial slot, uses
	// rehash to locate the next position
	string get(int key) {
		int startslot = hashfunction(key);

		string val;
		bool stop = false;
		bool found = false;
		int position = startslot;
		while (data[position] != "" && !found && !stop) {
			if (slots[position] == key) {
				found = true;
				val = data[position];
			}
			else {
				position = rehash(position);
				if (position == startslot) {
					stop = true;
				}
			}

		}
		return val;
	}

	friend ostream& operator<<(ostream& stream, HashTable& hash);


	string get(string keys) {
		int key = converter(keys);
		int startslot = hashfunction(key);

		string val;
		bool stop = false;
		bool found = false;
		int position = startslot;
		while (data[position] != "" && !found && !stop) {
			if (slots[position] == key) {
				found = true;
				val = data[position];
			}
			else {
				position = rehash(position);
				if (position == startslot) {
					stop = true;
				}
			}

		}
		return val;
	}

	friend ostream& operator<<(ostream& stream, HashTable& hash);
};



ostream& operator<<(ostream& stream, HashTable& hash) {
	for (int i = 0; i < hash.size; i++) {
		stream << hash.slots[i] << ": " << hash.data[i] << endl;
	}

	return stream;
}

int table_values() {

	HashTable h;
	h.put("WAFULA", "WAFULA information  IS HIDDEN FROM YOU");
	h.put("LIBERTY", "A Berea College student stdying");
	h.put(54, "cat");
	h.put(26, "dog");
	h.put(93, "lion");
	h.put(17, "tiger");
	h.put(77, "bird");
	h.put(31, "cow");
	h.put(44, "goat");
	h.put(55, "pig");
	h.put(20, "chicken");
	
	//cout << h << endl;
	h.put(20, "chicken");
	h.put(17, "tiger");
	h.put(20, "duck");
	cout << "You are going to enter the id of the animal to retrieve its name and other information" << endl;
	while (true) {
		int code;
		string code2;
		
		cout << "what is the animal's code" << endl;
		cin >> code2;
		//cin >> code;
		

	//	if (h.get(code) NULL) {
			cout << h.get(code2) << endl;
			
		//	cout << h.get(code) << endl;
		//}
		//if (code in h.key())
	}
		
		
	
}

int main( ){

	while (true) {
		table_values();
	}
	
	cout << "Change me!" << endl;

	char enter;
	cin >> enter;
return 0;
}

