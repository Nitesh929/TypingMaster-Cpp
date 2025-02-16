#include <iostream>
#include <iomanip>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

void displaySpecialization(const string &domainName, const string specialties[], const string definitions[], int size);
void certificate();
void displayPrices();

void Academor() {
    cout << BOLD << CYAN << "Welcome to Academor Internship Program!" << RESET << endl;
    cout << "\n" << BOLD << MAGENTA << "Domains Available:\n" << RESET;
    cout << YELLOW << "1. Computer Science\n"
         << "2. Management\n"
         << "3. Civil/Mechanical\n"
         << "4. Electronics and Communication\n"
         << "5. Bio-Technology\n" << RESET;

    cout << "\nEnter the domain number to view specializations: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cout << RED << "Invalid choice. Please try again!" << RESET << endl;
        return;
    }

    // Specializations and their definitions
    string computerScience[] = {"Web Development", "AI", "Machine Learning", "Cyber Security", "Cloud Computing", "Android Development", "AR/VR", "Data Science"};
    string csDefinitions[] = 
    {
        "Building websites and web applications using technologies like HTML, CSS, and JavaScript.",
        "Simulating human intelligence in machines to perform tasks like problem-solving and decision-making.",
        "Using algorithms to enable systems to learn and improve from data without being explicitly programmed.",
        "Protecting systems and networks from cyber threats, ensuring data security.",
        "Delivering computing services over the internet, such as storage and databases.",
        "Creating mobile applications for Android platforms using Java or Kotlin.",
        "Developing immersive experiences using augmented and virtual reality technologies.",
        "Analyzing large datasets to extract meaningful insights and trends."
    };

    string management[] = {"Digital Marketing", "Finance", "Human Resource", "Marketing", "Stock Market", "Business Analytics"};
    string mgmtDefinitions[] = 
    {
        "Promoting products or services online using tools like SEO, social media, and email campaigns.",
        "Managing money and investments for individuals or organizations.",
        "Recruiting, training, and managing employees to build a productive workforce.",
        "Creating strategies to promote and sell products or services effectively.",
        "Analyzing and trading financial assets in markets to generate profit.",
        "Using data to make informed business decisions and improve performance."
    };

    string civilMechanical[] = {"AutoCAD", "Electric Vehicle", "Car Design", "IC Design", "Construction Planning"};
    string civilMechDefinitions[] = 
    {
        "Creating precise 2D and 3D designs for engineering projects.",
        "Designing and building eco-friendly vehicles powered by electricity.",
        "Creating the aesthetic and functional aspects of vehicles.",
        "Designing and fabricating integrated circuits for electronics.",
        "Planning and managing construction projects efficiently."
    };

    string ece[] = {"IoT", "Robotics", "Embedded Systems", "Hybrid EV", "VLSI Design"};
    string eceDefinitions[] = 
    {
        "Connecting devices over the internet to collect and share data.",
        "Designing machines that can perform tasks autonomously or semi-autonomously.",
        "Developing hardware-software systems embedded within devices.",
        "Combining traditional and electric vehicle technologies for better performance.",
        "Creating compact and efficient semiconductor circuits for electronics."
    };

    string bioTech[] = {"Genetic Engineering", "Nano Technology", "Bioinformatics"};
    string bioTechDefinitions[] = 
    {
        "Modifying genetic material to improve or create new organisms.",
        "Manipulating matter at the nanoscale for medical or industrial purposes.",
        "Analyzing biological data using computational tools to solve complex problems."
    };

    switch (choice) {
        case 1: displaySpecialization("Computer Science", computerScience, csDefinitions, 8); break;
        case 2: displaySpecialization("Management", management, mgmtDefinitions, 6); break;
        case 3: displaySpecialization("Civil/Mechanical", civilMechanical, civilMechDefinitions, 5); break;
        case 4: displaySpecialization("Electronics and Communication", ece, eceDefinitions, 5); break;
        case 5: displaySpecialization("Bio-Technology", bioTech, bioTechDefinitions, 3); break;
    }
    certificate();
    displayPrices();
}

void displaySpecialization(const string &domainName, const string specialties[], const string definitions[], int size) 
{
    cout << "\n" << BOLD << BLUE << "Specializations in " << domainName << ":" << RESET << endl;
    for (int i = 0; i < size; i++) 
    {
        cout<<GREEN<<i + 1<< ". " << specialties[i] << RESET << ": " << YELLOW << definitions[i] << RESET << endl;
    }
}
void certificate()
{
    cout<<"\n"<<BOLD<<MAGENTA<<"<------------ Certificates ------------>" << RESET << endl;
    cout<<BOLD<<GREEN<<"1-> Course Completion Certificate from IIT Kharagpur Communique "<<RESET<<endl; 
    cout<<BOLD<<GREEN<<"2-> Internship Completion Certificate from cobranded Companies "<<RESET<<endl;
    cout<<BOLD<<GREEN<<"3-> LOR(Letter Of Recommendation) "<<RESET<<endl;
    cout<<BOLD<<GREEN<<"4-> Out standing Performance certificate (Based on performance)"<<RESET<<endl;

}
void displayPrices() 
{
    cout << "\n" << BOLD << MAGENTA << "<------------ Internship Plans ------------>" << RESET << endl;
    cout << BOLD << setw(30) << "Plan Type" 
         << "Price (With Referral)" << RESET << endl;
    cout << CYAN << setw(30) << "Self Blended" 
         << "= 4500 (3599)" << RESET << endl;
    cout << CYAN << setw(30) << "Blended (Recorded + Doubt)" 
         << "= 5500 (4599)" << RESET << endl;
    cout << CYAN << setw(30) << "Mentalet (Live Session)" 
         << "= 7500 (5599)" << RESET << endl;
}

int main() {
    Academor();

    cout << GREEN << "\nPress any key to exit..." << RESET;
    cin.ignore(); // Clear input buffer
    cin.get();    // Wait for a key press
    return 0;
}
