//// Default
//// Default
//#include <iostream>
//#include <list>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//using std::string;
//using std::list;
//
//#define KMAG  "\x1B[35m"
//#define KYEL  "\x1B[33m"
//#define KWHT  "\x1B[37m"
//#define KRED  "\x1B[31m"
//
//void _default();
//void info();
//void title();
//
//void printlane(string text);
//void printstart(string text);
//void printmid(string text);
//void printend(string text);
//void printred(string text);
//
//float number = 26;
//char chapter[] = "OOP Inheritance, GIT";
//
//
//
//class YouTubeChannel {
//private:
//    string Name;
//    int SubscriberCount;
//    list<string> PublishedVideoTitles;
//protected:
//    string OwnerName;
//public:
//    YouTubeChannel(string name, string ownerName) {
//        Name = name;
//        OwnerName = ownerName;
//        SubscriberCount = 0;
//    }
//
//    void GetInfo() {
//        cout << "   Name : " << Name << endl;
//        cout << "   Owner name : " << OwnerName << endl;
//        cout << "   Subscriber count : " << SubscriberCount << endl;
//        cout << "   Videos : " << endl;
//        for (string videoTitle : PublishedVideoTitles) {
//            cout << "   " << videoTitle << endl;
//
//
//        }
//        cout << endl;
//    }
//    void Subscribe() {
//        SubscriberCount++;
//    }
//    void Unsubscribe() {
//        if (SubscriberCount = 0) {
//            return;
//        }
//        SubscriberCount--;
//    }
//    void PublishVideo(string title) {
//        PublishedVideoTitles.push_back(title);
//    }
//};
//
//class CookingYouTubeChannel: public YouTubeChannel {
//public:
//    CookingYouTubeChannel(string name, string ownerName): YouTubeChannel(name, ownerName) {
//
//    }
//    void Practice() {
//        cout << "   " << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
//    }
//};
//
//int main()
//{
//    _default();
//
//
//    CookingYouTubeChannel CookingYChannel("Amy's Kitchen", "Amy");
//    CookingYouTubeChannel CookingYChannel2("John's Kitchen", "John");
//    //CookingYChannel.PublishVideo("Apple pie");
//    //CookingYChannel.PublishVideo("Chocolate cacke");
//    //CookingYChannel.Subscribe();
//    //CookingYChannel.Subscribe();
//    CookingYChannel.Practice();
//    CookingYChannel2.Practice();
//    CookingYChannel.GetInfo();
//
//
//    system("pause>0");
//}
//
//
//
//void space(int size) {
//    for (int i = 0; i < size; i++) {
//        cout << " ";
//    }
//}
//void _default() {
//    info();
//    title();
//}
//void info() {
//    printf(KMAG);
//
//    cout << endl;
//    space(1);
//    cout << "CodeBeauty - "
//        << "C++ FULL COURSE For Beginners "
//        << "(Learn C++ in 10 hours)"
//        << endl;
//}
//void title() {
//    printf(KYEL);
//
//    space(2);
//    cout << number << " - " << chapter;
//    cout << endl << endl;
//
//    printf(KWHT);
//}
//
//
//
//void printlane(string text) {
//    space(3);
//    cout << "   " << text << endl;
//}
//void printstart(string text) {
//    space(3);
//    cout << "   " << text;
//}
//void printmid(string text) {
//    cout << text;
//}
//void printend(string text) {
//    cout << text << endl;
//}
//
//void printred(string text) {
//    printf(KRED);
//    cout << text;
//    printf(KWHT);
//}