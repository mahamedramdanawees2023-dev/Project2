#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
class lin {
public:
	node* head;
	lin() {
		head = nullptr;
	}
	bool is_empty() {
		return (head == nullptr);
	}
	void insert_fir(int value) {
		node* newnode = new node();
		newnode->data = value;
		if (is_empty()) {
			newnode->next = nullptr;
			head = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}

	void insert_Last(int ddd) {
		node* newnode = new node();
		newnode->data = ddd;
		newnode->next = nullptr;
		if (is_empty()) {
			newnode->next = nullptr;
			head = newnode;
		}
		else {
			node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}

	void insert_between(int pos, int value) {
		if (is_empty()) {
			insert_fir(value);
		}
		else {
			node* temp = head;
			node* newnode = new node();
			newnode->data = value;
			while (temp != nullptr) {
				if (temp->data == pos) {
					newnode->next = temp->next;
					temp->next = newnode;
					break;
				}
				temp = temp->next;
			}
		}
	}

	int count() {
		node* ttt = head;
		int counter = 0;
		while (ttt != nullptr) {
			counter++;
			ttt = ttt->next;
		}
		return counter;
	}
	void Search(int serchval) {
		node* tail = head;
		int pos = 1;
		bool found = false;
		while (tail != nullptr) {
			if (tail->data == serchval) {
				found = true;
				break;
			}
			pos++;
			tail = tail->next;
		}
		if (found) cout << "The element found in pos = " << pos;
		if (!found) cout << "The element not found";
	}
	void Repetive(int value) {
		node* r = head;
		int count = 0;
		while (r != nullptr) {
			if (r->data == value) {
				count++;
			}
			r = r->next;
		}
		cout << "the number " << value << " repetive " << count;
	}
	void delete_node(int val) {
		if (is_empty()) {
			cout << "no node to delete !";
			return;
		}
		if (head->data == val) {
			node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		node* prev = nullptr;
		node* curr = head;
		while (curr != nullptr) {
			if (curr->data == val) {
				prev->next = curr->next;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		cout << "Node not found!" << endl;
	}
	void replace(int oldval, int newval) {
		node* d = head;
		while (d != nullptr) {
			if (d->data == oldval) {
				d->data = newval;
				break;
			}
			d = d->next;
		}
		cout << "(" << oldval << ") Replace to (" << newval << ")" << "\n";
	}
	void display() {
		node* t = head;
		while (t != nullptr) {
			cout << "-->" << t->data << " ";
			t = t->next;
		}
		cout << "\n";
	}
	void reverse() {
		int count = 0;
		node* t = head;
		while (t != nullptr) {
			count++;
			t = t->next;
		}
		for (int i = count - 1; i >= 0; i--) {
			t = head;
			for (int j = 0; j < i; j++) {
				t = t->next;
			}
			cout << t->data << " ";
		}
		cout << "\n";
	}
	void sortAscending() {
		if (head == nullptr) return;
		for (node* i = head; i != nullptr; i = i->next) {
			for (node* j = i->next; j != nullptr; j = j->next) {
				if (i->data > j->data) {
					int temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
	}
	void sortDescending() {
		if (head == nullptr) return;
		for (node* i = head; i != nullptr; i = i->next) {
			for (node* j = i->next; j != nullptr; j = j->next) {
				if (i->data < j->data) {
					int temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
	}
	void swap(int val1, int val2) {
		node* d = head;
		node* n1 = nullptr;
		node* n2 = nullptr;
		while (d != nullptr) {
			if (d->data == val1) n1 = d;
			if (d->data == val2) n2 = d;
			d = d->next;
		}
		if (n1 != nullptr && n2 != nullptr) {
			int temp = n1->data;
			n1->data = n2->data;
			n2->data = temp;
		}
	}
	void max_min() {
		if (is_empty()) {
			cout << "List is empty!\n";
			return;
		}
		node* m = head;
		int max = head->data;
		int min = head->data;
		while (m != nullptr) {
			if (m->data > max) {
				max = m->data;
			}
			else if (m->data < min) {
				min = m->data;
			}
			m = m->next;
		}
		cout << "The Max = " << max << endl;
		cout << "The Min = " << min << endl;
	}

	void sum_avg_num_even_odd() {
		if (is_empty()) {
			cout << "NO elements !!!";
			return;
		}
		int sumeven = 0; int counteven = 0;
		int sumodd = 0; int countodd = 0;
		node* tt = head;
		while (tt != nullptr) {
			if (tt->data % 2 == 0) {
				sumeven += tt->data;
				counteven++;
			}
			else if (tt->data % 2 != 0) {
				sumodd += tt->data;
				countodd++;
			}
			tt = tt->next;
		}
		cout << "Sum of even = " << sumeven << "\n";
		if (counteven > 0) cout << "Avg of even = " << (double)sumeven / counteven << "\n";
		cout << "Sum of odd = " << sumodd << "\n";
		if (countodd > 0) cout << "Avg of odd = " << (double)sumodd / countodd << "\n";
	}
	void positions_SumAvg() {
		if (head == nullptr) {
			cout << "List is empty!\n";
			return;
		}
		int sumEvenPos = 0, countEvenPos = 0;
		int sumOddPos = 0, countOddPos = 0;
		int pos = 1;
		node* t = head;
		while (t != nullptr) {
			if (pos % 2 == 0) {
				sumEvenPos += t->data;
				countEvenPos++;
			}
			else {
				sumOddPos += t->data;
				countOddPos++;
			}
			pos++;
			t = t->next;
		}
		cout << "--- Even Positions ---\n";
		if (countEvenPos > 0) {
			cout << "Sum = " << sumEvenPos << "\n";
			cout << "Average = " << (double)sumEvenPos / countEvenPos << "\n";
		}
		else {
			cout << "No even positions found.\n";
		}
		cout << "--- Odd Positions ---\n";
		if (countOddPos > 0) {
			cout << "Sum = " << sumOddPos << "\n";
			cout << "Average = " << (double)sumOddPos / countOddPos << "\n";
		}
	}
};
int main() {
	lin h;
	int choice, v, pos, oldval, newval;
	do {
		cout << "\n=============== Menu ===============\n";
		cout << "1. Insert at Last \n";
		cout << "2. Display List \n";
		cout << "3. Count Nodes \n";
		cout << "4. Search \n";
		cout << "5. Replace \n";
		cout << "6. Sort Ascending \n";
		cout << "7. Sort Descending \n";
		cout << "8. Print Reversed \n";
		cout << "9. Delete Node \n";
		cout << "10. Find MAX & MIN \n";
		cout << "11. Sum & Avg for Even/Odd Numbers \n";
		cout << "12. Sum & Avg for Even/Odd Positions \n";
		cout << "0. Exit \n";
		cout << "====================================\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter value to insert: ";
			cin >> v;
			h.insert_Last(v);
			cout << "Inserted successfully!\n";
			break;

		case 2:
			cout << "The List: ";
			h.display();
			break;

		case 3:
			cout << "The number of nodes = " << h.count() << "\n";
			break;

		case 4:
			cout << "Enter value to search for: ";
			cin >> v;
			h.Search(v);
			cout << "\n";
			break;

		case 5:
			cout << "Enter the old value: ";
			cin >> oldval;
			cout << "Enter the new value: ";
			cin >> newval;
			h.replace(oldval, newval);
			break;

		case 6:
			h.sortAscending();
			cout << "List sorted ascendingly.\n";
			h.display();
			break;

		case 7:
			h.sortDescending();
			cout << "List sorted descendingly.\n";
			h.display();
			break;

		case 8:
			cout << "List in reverse: ";
			h.reverse();
			break;

		case 9:
			cout << "Enter value to delete: ";
			cin >> v;
			h.delete_node(v);
			break;

		case 10:
			cout << "MAX & MIN:\n";
			h.max_min();
			break;

		case 11:
			h.sum_avg_num_even_odd();
			break;

		case 12:
			h.positions_SumAvg();
			break;

		case 0:
			cout << "Exiting the program...\n";
			break;

		default:
			cout << "Invalid choice!\n";
		}

	} while (choice != 0);
}