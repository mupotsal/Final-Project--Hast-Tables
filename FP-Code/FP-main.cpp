// Final Project
// Liberty Mupotsa and Anthony W Wafula

#include <iostream>

using namespace std;

#include <iostream>
#include <string>
using namespace std;

class HashTable {
public:
	static const int size = 90; // initial size of hash table is prime to help with collision resolution// make this big so that it can take the values of many items.
	int slots[size]; // list to hold key items
	string data[size]; // list to hold data values 


	//modify the following hashing function so that one can use strings as Keys to data
	void setfunction(int key) {
		slots[key] = NULL;
		data[key].clear();
		
	}
	int converter(string key) { // This converts keys to a number.
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
		return (key) % size;
	}
	// Computes original hashvalue, and if slot is
	// not empty iterates until empty slot is found // Using linear probing for collision resolution
	int square = 0;
	int rehash(int oldhash) {
		square += 1;
		return (oldhash + square*square) % size; // They used linear probing but we can change that to quadratic probing to reduce clustering.
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

	// remove an element from the hashtable
	void remove(int key) {
		//int key = converter(keys);
		int startslot = hashfunction(key); // may need to mpdify this to enhance quadratic probing

		string val;
		bool stop = false;
		bool found = false;
		int position = startslot;
		while (position != size && !found && !stop) {
			if (slots[position] == key) {
				found = true;
				setfunction(key);
				
			}
			else {
				position = rehash(position);
				if (position == startslot) {
					found = true;
					
					
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
		while (position != size && !found && !stop) {
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

	// the following method checks if the key is in the map.
	bool in(int key) {
		int startslot = hashfunction(key);

		string val;
		bool stop = false;
		bool found = false;
		int position = startslot;
		while (position != size && !found && !stop) {
			if (slots[position] == key) {
				//returns true if the value is found
				return true;	

			}
			else {
				position = rehash(position);
				if (position == startslot) {
					//stops if the value is not found
					stop= true;
				}
			}

		}
		return false;
	}


	//find the lenth of the values in the hashtable
	int len() {
		int the_size = 0;
		for (int i = 0; i < size; i++) {
			//adds up values cummulativelly 
			if (data[i].empty() == 0) {
				the_size += 1;
			}
		}
		return the_size;
	}

	friend ostream& operator<<(ostream& stream, HashTable& hash);

	//searchs to find a value in the table
	string get(string keys) {
		int key = converter(keys);
		int startslot = hashfunction(key); // may need to mpdify this to enhance quadratic probing

		string val;
		bool stop = false;
		bool found = false;
		int position = startslot;
		while (position != size && !found && !stop) {
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
	//frind or overload
	friend ostream& operator<<(ostream& stream, HashTable& hash);
};


//overloading
ostream& operator<<(ostream& stream, HashTable& hash) {
	for (int i = 0; i < hash.size; i++) {
		stream << hash.slots[i] << ": " << hash.data[i] << endl;
	}

	return stream;
}


//hashtable values
int table_values() {

	HashTable h;
	h.put("WAFULA", "WAFULA information  IS HIDDEN FROM YOU");
	h.put("LIBERTY", "A Berea College student stdying");
	h.put(54, "cat");	
	h.put(26, "dog");
	h.put(46, "horse");
	h.put(56, "donkey");
	h.put(93, "lion");
	h.put(17, "tiger");
	h.put(77, "bird");
	h.put(31, "cow");
	h.put(44, "goat");
	h.put(55, "pig");
	h.put(20, "chicken");
	h.put(24, "hen");
	

	
	cout << h <<" This is the end of the first table"<< endl;
	
	h.put(21, "duck");
	h.remove(17);
	cout << "This is the second table" << endl;
	cout << h << endl;
	cout << "You are going to enter the id of the animal to retrieve its name and other information" << endl;
	cout << "Checking to see if the value is in the hash table " << h.in(20) << endl;
	cout << "Checking to see if (5)the value is in the hash table " << h.in(25) << endl;
	cout << "Checking to see  the len  " << h.len() << endl;
	while (true) {
		int code;
		string code2;		
		cout << "If you want to search for Animals type y and if you want to search for students files type s" << endl;
		string choice;
		cin >> choice;
		if (choice == "y") {
			
			cout << "What is the code of the animal?" << endl;
			cin >> code;
			cout << h.get(code) << endl;
		}
		else {
			
			cout << "What is the code of the Student?" << endl;
			cin >> code2;
			cout << h.get(code2) << endl;
		}

	}
		
		
	
}
//main function
int main( ){

	while (true) {
		table_values();
	}
	
	cout << "Change me!" << endl;

	char enter;
	
	cin >> enter;
return 0;
}

