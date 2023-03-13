/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: testbig.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
																				NOTHING CAN BE CHANGED IN THIS FILE
																				DO NOT POST THIS FILE IN CANVAS
																				WE WILL USE DIFFERENT TEST FOR GRAING
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
ONLY INCLUDE HERE. YOU CANNOT ADD ANYTHING HEREe
-----------------------------------------------------------------*/
#include "longnumber.h"
#define TOUGHTEST
static int marks = 5;

/*--------------------------------------------------------
long number class
----------------------------------------------------------*/
class testbig {
public:
		testbig() {
				small_test_();
				real_exam_();
		}

private:
		void small_test_();
		void real_exam_();

		void basic_();
		void test_add_();
		void test_add_(const int a, const int b, const int ans, bool display = true);
		void test_add_(const char* a, const char* b, const char* ans, bool display = true);
		void test_multiply_();
		void test_multiply_(const int  a, const int  b, const int ans, bool display = true);
		void test_multiply_(const char* a, const int  b, const char* ans, bool display = true);
		void test_factorial_();
		void test_factorial_(int n, const char* s);
};

/*----------------------------------------------------------------
small test
-----------------------------------------------------------------*/
void testbig::small_test_() {
		cout << "------------------  small tests starts ----------------\n";
		cout << "Your marks so for " << marks << endl;
#if 1
		{
				int k = -1986;
				const char* n = "1986";
				longnumber l(k);
				cout << "l(unsigned int) = " << l << endl;
				int start = 0;
				int d = l.num_digits();
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				const char* n = "-123567890123567890123567890123567890123567890123567890123567890";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l.is_negative());
				int start = 1;
				int d = l.num_digits();
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif

#if 1
		{
				test_add_(1986, 19, (1986 + 19));
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif

#if 1
		{
				test_add_("99", "1", "100");
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				test_multiply_(1986, 19, (1986 * 19));
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				test_multiply_("89977", 46, "4138942");
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				const char* a = "3628800";
				test_factorial_(10, a);
				marks += 15;
				cout << "Your marks so for " << marks << endl;
		}
		cout << "I will make you suffer in real exam" << endl;
#endif
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testbig::test_add_(const int  a, const int  b, const int ans, bool display) {
		longnumber c = a + b;
		if (c != ans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != ans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testbig::test_add_(const char* a, const char* b, const char* ans, bool display) {
		longnumber c = longnumber(a) + longnumber(b);
		longnumber lans = longnumber(ans);
		if (c != lans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != lans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void testbig::test_multiply_(const int  a, const int  b, const int ans, bool display) {
		longnumber c = longnumber(a) * b;
		longnumber lans = longnumber(ans);
		if (c != lans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != lans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void testbig::test_multiply_(const char* a, const int  b, const char* ans, bool display) {
		longnumber c = longnumber(a) * b;
		longnumber lans = longnumber(ans);
		if (c != lans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != lans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}


/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void testbig::test_factorial_(int n, const char* s) {
		longnumber ans(s);
		std::clock_t c_start = std::clock();
		longnumber a = longnumber::fact(n);
		std::clock_t c_end = std::clock();
		double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
		cout << "Factorial of " << n << " = " << endl;
		cout << a << endl;
		if (a != ans) {
				cout << "Expected ans was " << ans << endl;
		}
		cout << "CPU time used: " << time_elapsed_ms / 1000 << " seconds\n";
		assert(a == ans);
}

/*----------------------------------------------------------------
																						REMOVE ALL REAL TESTS START
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
test basic
-----------------------------------------------------------------*/
void testbig::basic_() {
		{
				int n = 1986;
				longnumber l(n);
				cout << "l(unsigned int) = " << l << endl;
		}

		{
				int n = -1986;
				longnumber l(n);
				cout << "l(unsigned int) = " << l << endl;
		}


		{
				const char* n = "0";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == int(0));
		}

		{
				const char* n = "1986";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == 1986);
		}

		{
				const char* n = "-1986";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == longnumber(-1986));
		}

		{
				const char* n = "-123567890123567890123567890123567890123567890123567890123567890";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l.is_negative());
				int start = 1;
				int d = l.num_digits();
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
		}

		{
				const char* n = "1234567890123567890123567890123567890123567890123567890123567890";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				int d = l.num_digits();
				assert(l.is_positive());
				int start = 0;
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
		}

		{
				//TESTING number of digits
				{
						longnumber l(0);
						assert(l.is_positive());
						assert(l.num_digits() == 1);
				}
				{
						longnumber l(-3);
						assert(l.is_negative());
						assert(l.num_digits() == 1);
				}
				{
						longnumber l(-1986);
						assert(l.is_negative());
						assert(l.num_digits() == 4);
						assert(l != longnumber(1986));
				}
		}

		{
				//TESTING 0, +1 -1
				{
						longnumber l(0);
						assert(l == 0);
				}
				{
						longnumber l(1);
						assert(l == 1);
						assert(l != -1);
				}
				{
						longnumber l(-1);
						assert(l == -1);
						assert(l != 1);
				}
				{
						longnumber l(-1986);
						assert(l != 1986);
				}

				{
						longnumber l(1986);
						assert(l != -1986);
				}
		}
#ifdef TOUGHTEST
		{
				const char* n = "+1986";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == 1986);
		}
		{
				const char* n = "+000001986";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == longnumber(1986));
				assert(l != longnumber(-1986));
		}

		{
				const char* n = "-000001986";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == longnumber(-1986));
				assert(l != longnumber(1986));
		}
		{
				const char* n = "-0";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l == longnumber(0));
		}
		{
				const char* n = "+1234567890123567890123567890123567890123567890123567890123567890";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				int d = l.num_digits();
				assert(l.is_positive());
				int start = 1;
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
		}
#endif
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testbig::test_add_() {
		test_add_(1986, 19, (1986 + 19));
		test_add_(1986, 0, (1986 + 0));

		test_add_(1986, 0, (1986 + 0));
		test_add_(0, 1986, (1986 + 0));
		test_add_(0, 0, (0 + 0));
		test_add_(1986, 1, (1986 + 1));
		test_add_(1, 1986, (1986 + 1));
		const int t[] = { 18379, 14180, 23697, 2688, 19137, 26732, 12925, 5367 };
		int s = sizeof(t) / sizeof(int);
		for (int i = 0; i < s; i = i + 2) {
				test_add_(t[i], t[i + 1], (t[i] + t[i + 1]));
		}

		test_add_("3490529510847650949147849619903898133417764638493387843990820577",
				"32769132993266709549961988190834461413177642967992942539798288533",
				"36259662504114360499109837810738359546595407606486330383789109110");

}


/*----------------------------------------------------------------
test multiply
-----------------------------------------------------------------*/
void testbig::test_multiply_() {
		test_multiply_(1986, 19, (1986 * 19));
		test_multiply_(1986, 0, (1986 * 0));
		test_multiply_(0, 5, (0 * 5));
		test_multiply_(0, 0, (0 * 0));
		test_multiply_(1986, 1, (1986 * 1));
		test_multiply_(1, 1986, (1986 * 1));
		test_multiply_(1986, 1, (1986 * 1));
		test_multiply_("89977", 46, "4138942");
		const int t[] = { 18379, 14180, 23697, 2688, 19137, 26732, 12925, 5367 };
		int s = sizeof(t) / sizeof(int);
		for (int i = 0; i < s; i = i + 2) {
				test_multiply_(t[i], t[i + 1], (t[i] * t[i + 1]));
		}
#ifdef TOUGHTEST
		test_multiply_(1986, -19, (1986 * -19));
		test_multiply_(0, -5, (0 * -5));
		test_multiply_(1986, -1, (1986 * -1));
#endif
}

/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void testbig::test_factorial_() {
		{
				const char* a = "3628800";
				test_factorial_(10, a);
		}
		{
				const char* a = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
				test_factorial_(100, a);
		}
		{
				const char* a = "402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
				test_factorial_(1000, a);
		}
}

/*----------------------------------------------------------------
test bed big
-----------------------------------------------------------------*/
void testbig::real_exam_() {
		cout << "------------------  real exam starts ----------------\n";
		basic_();
		marks += 10;
		cout << "Your marks so for " << marks << endl;
		test_add_();
		marks += 10;
		cout << "Your marks so for " << marks << endl;
		test_multiply_();
		marks += 10;
		cout << "Your marks so for " << marks << endl;
		test_factorial_();
		marks += 20;
		cout << "total marks " << marks << endl;
		cout << "If I find you copying, you will get 0 marks" << endl;
}

/*----------------------------------------------------------------
																						REMOVE ALL REAL TESTS ENDS
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
The main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		cout << "------- Start----------\n";
		testbig l;
		cout << "------- END----------\n";
		return 0;
}
