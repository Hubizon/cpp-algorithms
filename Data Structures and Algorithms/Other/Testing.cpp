// simple program tester

#define cin in
#define cout out

void brute() { }

void solve() { }

bool compareFile() {
	ifstream in1("brute.out"), in2("solve.out");

	stringstream s1, s2;
	s1 << in1.rdbuf();
	s2 << in2.rdbuf();

	in1.close(), in2.close();

	return (s1.str() == s2.str());
}

void test() {
	for (int z = 0; z < 1000; z++) {
		ofstream in("test.in");

		// generate a test

		in.close();

		brute();
		solve();

		if (!compareFiles()) {
			cerr << "wtf";
			exit(0);
		}
	}
}
