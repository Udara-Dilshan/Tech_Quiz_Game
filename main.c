#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int score = 0;
int totalQuestions = 10;

char subjects[9][50] = {
    "Artificial Intelligence and Machine Learning",
    "Cybersecurity and Ethical Hacking",
    "Internet of Things (IoT)",
    "Blockchain Technology",
    "Data Science and Big Data Analytics",
    "Cloud Computing",
    "Virtual Reality and Augmented Reality",
    "Quantum Computing",
    "Robotics and Automation"
};

void showMainMenu();
void startQuiz();
void selectSubject(int subjectIndex);
void showQuiz(int subjectIndex);
void displayCorrect();
void displayFail();
void showWin();
void showExitMessage();
void clearScreen();

int main() {
    showMainMenu();  
    return 0;
}

void showMainMenu() {
    int choice;

    while (1) {
        clearScreen();
        printf("Welcome to the Quiz Game!\n");
        printf("1. Start\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            startQuiz();
        } else if (choice == 2) {
            exit(0);
        } else {
            printf("Invalid choice! Try again.\n");
            _getch();
        }
    }
}

void startQuiz() {
    int choice;

    while (1) {
        clearScreen();
        printf("Select a Subject:\n");
        for (int i = 0; i < 9; i++) {
            printf("%d. %s\n", i + 1, subjects[i]);
        }
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9) {
            selectSubject(choice - 1);  
        } else {
            printf("Invalid choice! Try again.\n");
            _getch();
        }
    }
}

void selectSubject(int subjectIndex) {
    score = 0;  
    showQuiz(subjectIndex);
}

void showQuiz(int subjectIndex) {
    
    char questions[9][10][256] = {
        { // AI and ML
            "1. What is the main goal of Artificial Intelligence?",
            "2. Which algorithm is commonly used for supervised learning?",
            "3. What is the primary use of Natural Language Processing?",
            "4. Which of these is a common neural network type?",
            "5. What is the function of a decision tree in machine learning?",
            "6. Which library is commonly used in Python for AI development?",
            "7. What does 'training' mean in machine learning?",
            "8. What is overfitting in a machine learning model?",
            "9. Which of these is an example of a supervised learning algorithm?",
            "10. Which programming language is most commonly used in AI development?"
        },
        { // Cybersecurity
            "1. What is the main purpose of a firewall?",
            "2. What does the acronym 'VPN' stand for?",
            "3. What is the most common method of cyber attack?",
            "4. What does phishing mean in cybersecurity?",
            "5. What is the role of encryption in cybersecurity?",
            "6. What is the function of an antivirus program?",
            "7. What is two-factor authentication (2FA)?",
            "8. Which protocol is used for secure communication over the internet?",
            "9. What does 'zero-day exploit' refer to?",
            "10. What is a DDoS attack?"
        },
        { // IoT
            "1. What does 'IoT' stand for?",
            "2. What is the main benefit of IoT?",
            "3. Which protocol is commonly used in IoT devices?",
            "4. What is a smart home in the context of IoT?",
            "5. What kind of data is typically collected by IoT devices?",
            "6. What is the role of cloud computing in IoT?",
            "7. Which of these is an example of an IoT device?",
            "8. What is the main challenge in IoT security?",
            "9. What is the function of a gateway in IoT?",
            "10. What technology is often used for communication in IoT devices?"
        },
        { // Blockchain
            "1. What is the main purpose of blockchain technology?",
            "2. Which technology is used to verify transactions in blockchain?",
            "3. What is a 'block' in blockchain?",
            "4. What is Bitcoin?",
            "5. What does 'mining' refer to in the context of blockchain?",
            "6. What is the purpose of a smart contract?",
            "7. What does the term 'decentralized' mean in blockchain?",
            "8. What is a public key in blockchain?",
            "9. What is the primary advantage of blockchain over traditional databases?",
            "10. Which industry is most widely adopting blockchain technology?"
        },
        { // Data Science
            "1. What is the primary goal of Data Science?",
            "2. What does the term 'big data' refer to?",
            "3. Which programming language is most popular for data science?",
            "4. What is machine learning in the context of data science?",
            "5. What is a data scientist's primary responsibility?",
            "6. What does data cleaning refer to in data science?",
            "7. What is the difference between structured and unstructured data?",
            "8. What is a data visualization?",
            "9. What is the purpose of a regression model?",
            "10. What is clustering in data science?"
        },
        { // Cloud Computing
            "1. What is cloud computing?",
            "2. What are the main benefits of cloud computing?",
            "3. Which of the following is a cloud computing service model?",
            "4. What does IaaS stand for?",
            "5. What is the role of virtualization in cloud computing?",
            "6. What is a public cloud?",
            "7. Which company is known for its cloud computing services?",
            "8. What is a cloud provider?",
            "9. What is the primary advantage of cloud storage?",
            "10. What does SaaS stand for?"
        },
        { // VR and AR
            "1. What is Virtual Reality?",
            "2. What is Augmented Reality?",
            "3. Which technology is used in AR?",
            "4. What does the term 'immersive experience' refer to?",
            "5. What is a VR headset used for?",
            "6. What is the difference between VR and AR?",
            "7. What are the applications of VR in education?",
            "8. What is the primary use of AR in mobile apps?",
            "9. What does haptic feedback provide in VR?",
            "10. What industries benefit the most from VR and AR?"
        },
        { // Quantum Computing
            "1. What is a qubit in quantum computing?",
            "2. What is superposition in quantum computing?",
            "3. What is entanglement in quantum computing?",
            "4. What makes quantum computers faster than classical computers?",
            "5. What is a quantum gate?",
            "6. What is quantum teleportation?",
            "7. Which algorithm is associated with quantum computing?",
            "8. What is quantum cryptography?",
            "9. What are the applications of quantum computing?",
            "10. Which company is leading in quantum computing research?"
        },
        { // Robotics
            "1. What is the main function of robotics?",
            "2. What is an industrial robot?",
            "3. What is the definition of automation?",
            "4. Which of these is an example of a robotic arm?",
            "5. What is the role of sensors in robotics?",
            "6. What is the difference between AI and robotics?",
            "7. What is a robot's 'end effector'?",
            "8. Which of these industries uses robots the most?",
            "9. What is the role of machine learning in robotics?",
            "10. What is the future trend for robotics?"
        }
    };

    ]
    char options[9][10][4][100] = {
        { // AI and ML
            {"1. Data processing", "2. Speech recognition", "3. Learning from data", "4. Image recognition"},
            {"1. Linear Regression", "2. K-Nearest Neighbors", "3. Decision Trees", "4. Naive Bayes"},
            {"1. Text summarization", "2. Sentiment analysis", "3. Translation", "4. All of the above"},
            {"1. Convolutional Neural Networks", "2. Recurrent Neural Networks", "3. Both", "4. None of the above"},
            {"1. Classification", "2. Regression", "3. Clustering", "4. Decision-making"},
            {"1. TensorFlow", "2. PyTorch", "3. Keras", "4. All of the above"},
            {"1. Model evaluation", "2. Feature selection", "3. Learning patterns from data", "4. Testing models"},
            {"1. Data leakage", "2. Overfitting", "3. Underfitting", "4. Both overfitting and underfitting"},
            {"1. Logistic Regression", "2. Random Forest", "3. Support Vector Machine", "4. Naive Bayes"},
            {"1. Python", "2. C++", "3. Java", "4. R"}
        },
        { // Cybersecurity
            {"1. To block unauthorized access", "2. To allow only authorized access", "3. To filter malicious traffic", "4. All of the above"},
            {"1. Virtual Private Network", "2. Very Private Network", "3. Verified Private Network", "4. Video Protocol Network"},
            {"1. Malware attacks", "2. Phishing", "3. Brute force attacks", "4. All of the above"},
            {"1. Sending deceptive emails", "2. Stealing credit card information", "3. Creating fake websites", "4. None of the above"},
            {"1. Secure sensitive data", "2. Ensure privacy", "3. Protect data during transmission", "4. All of the above"},
            {"1. Identify and remove malware", "2. Block hackers", "3. Protect the system", "4. None of the above"},
            {"1. A password", "2. A physical token", "3. A one-time password", "4. Both a password and a one-time password"},
            {"1. HTTP", "2. HTTPS", "3. TCP/IP", "4. FTP"},
            {"1. An attack that exploits an unknown vulnerability", "2. A known attack", "3. An attack using a virus", "4. A brute force attack"},
            {"1. Distributed Denial of Service", "2. Direct Denial of Service", "3. Denial of Service", "4. None of the above"}
        },
        { // IoT
            {"1. Internet of Things", "2. Internet of Technology", "3. Intelligent Objects Theory", "4. Integrated Object Tracking"},
            {"1. To create smart devices", "2. To connect devices to the internet", "3. To store data", "4. To create mobile apps"},
            {"1. Zigbee", "2. Bluetooth", "3. Wi-Fi", "4. MQTT"},
            {"1. Smart lights and thermostats", "2. Smartwatches", "3. Home security cameras", "4. All of the above"},
            {"1. Temperature data", "2. Movement data", "3. Location data", "4. All of the above"},
            {"1. To store and analyze data", "2. To process data locally", "3. To improve device security", "4. To power devices"},
            {"1. Smart refrigerators", "2. Fitness trackers", "3. Drones", "4. All of the above"},
            {"1. Device authentication", "2. Data encryption", "3. Secure communication", "4. All of the above"},
            {"1. To convert data to JSON", "2. To route messages between devices", "3. To process data", "4. To update firmware"},
            {"1. Zigbee", "2. Bluetooth Low Energy", "3. Wi-Fi", "4. All of the above"}
        },
        { // Blockchain
            {"1. To track cryptocurrency transactions", "2. To provide secure, decentralized data storage", "3. To facilitate payment transactions", "4. All of the above"},
            {"1. Proof of work", "2. Consensus algorithm", "3. Public ledger", "4. Smart contracts"},
            {"1. A transaction record", "2. A unit of data", "3. A validator node", "4. A block in the blockchain"},
            {"1. A decentralized cryptocurrency", "2. A digital ledger", "3. A centralized database", "4. A public ledger"},
            {"1. To create new cryptocurrencies", "2. To verify transactions", "3. To mine cryptocurrencies", "4. To store data"},
            {"1. To automate transactions", "2. To verify the blockchain network", "3. To ensure data integrity", "4. To store smart contracts"},
            {"1. It can be accessed by anyone", "2. It is stored on a central server", "3. It is controlled by a single entity", "4. It is immutable and decentralized"},
            {"1. A private key", "2. A wallet address", "3. A public key", "4. A hash function"},
            {"1. Faster transaction speeds", "2. Better data integrity", "3. Greater scalability", "4. Better security"},
            {"1. Health industry", "2. Finance industry", "3. Legal industry", "4. All of the above"}
        },
        { // Data Science
            {"1. To extract insights from data", "2. To store data in databases", "3. To create models", "4. To visualize data"},
            {"1. Data that is too large to process", "2. Data that requires specialized software", "3. Data that is noisy", "4. Data that needs cleaning"},
            {"1. R", "2. Python", "3. SQL", "4. Java"},
            {"1. To classify data", "2. To make predictions", "3. To cluster data", "4. To clean data"},
            {"1. To analyze data", "2. To prepare data", "3. To clean data", "4. To deploy models"},
            {"1. Correcting missing values", "2. Removing outliers", "3. Removing duplicate data", "4. All of the above"},
            {"1. Structured is organized data", "2. Unstructured data is more organized", "3. Structured data is freeform", "4. Both are the same"},
            {"1. Graphs", "2. Charts", "3. Tables", "4. Diagrams"},
            {"1. To predict future values", "2. To understand relationships between variables", "3. To categorize data", "4. To group similar data"},
            {"1. Grouping similar items", "2. Labeling data", "3. Predicting outcomes", "4. Identifying patterns"}
        },
        { // Cloud Computing
            {"1. A distributed network of servers", "2. A web-based storage platform", "3. A virtualized computing service", "4. A data center"},
            {"1. Scalability", "2. Reliability", "3. Flexibility", "4. All of the above"},
            {"1. IaaS", "2. PaaS", "3. SaaS", "4. All of the above"},
            {"1. Infrastructure as a Service", "2. Platform as a Service", "3. Software as a Service", "4. None of the above"},
            {"1. Sharing resources on-demand", "2. Storing data securely", "3. Providing virtual servers", "4. Deploying applications"},
            {"1. It is owned by a third party", "2. It is used by a single organization", "3. It offers free services", "4. It is private"},
            {"1. Amazon Web Services", "2. Google Cloud", "3. Microsoft Azure", "4. All of the above"},
            {"1. A cloud platform provider", "2. A user accessing cloud services", "3. A cloud security protocol", "4. A cloud data center"},
            {"1. It offers high availability", "2. It requires physical storage", "3. It uses a subscription model", "4. It is on-premises"},
            {"1. Software as a Service", "2. Platform as a Service", "3. Infrastructure as a Service", "4. None of the above"}
        },
        { // VR and AR
            {"1. A digital environment", "2. A physical environment", "3. A virtual representation of reality", "4. An interactive simulation"},
            {"1. Overlays digital elements on real-world views", "2. Immerses the user in a virtual environment", "3. Offers a simulated experience", "4. None of the above"},
            {"1. GPS", "2. Computer vision", "3. Sensors", "4. Cameras"},
            {"1. Feeling like you're part of the virtual world", "2. Feeling like you're part of the physical world", "3. Experience limited interaction", "4. None of the above"},
            {"1. To display the VR environment", "2. To simulate real-world movements", "3. To give audio cues", "4. To create a virtual environment"},
            {"1. Virtual Reality immerses you in an environment", "2. Augmented Reality adds digital elements to the real world", "3. Both", "4. Neither"},
            {"1. Online classrooms", "2. VR simulations", "3. VR/AR training", "4. All of the above"},
            {"1. For geolocation services", "2. For gaming and entertainment", "3. To blend physical and digital worlds", "4. To create 3D graphics"},
            {"1. Force feedback", "2. Visual displays", "3. Touch feedback", "4. Audio cues"},
            {"1. Healthcare", "2. Gaming", "3. Education", "4. All of the above"}
        },
        { // Quantum Computing
            {"1. The smallest unit of information in quantum computing", "2. A type of quantum circuit", "3. A binary state", "4. A form of data storage"},
            {"1. When a qubit can represent both 0 and 1", "2. The ability of a qubit to exist in multiple states at once", "3. The process of measuring qubit state", "4. When a qubit is in a single state"},
            {"1. When two qubits are linked together", "2. When qubits interact with each other", "3. When a qubit is isolated", "4. When a qubit is unstable"},
            {"1. Because quantum computers use binary logic", "2. Because quantum computers have multiple states", "3. Because of classical algorithms", "4. Due to quantum tunneling"},
            {"1. A simple logic gate", "2. A quantum state control", "3. A unit of data storage", "4. A machine learning model"},
            {"1. The ability to transfer data instantly", "2. A quantum method of communication", "3. The concept of transferring quantum states", "4. A method for error-correction"},
            {"1. Shor's algorithm", "2. Grover's algorithm", "3. Both", "4. Neither"},
            {"1. A method to protect quantum information", "2. A type of quantum key distribution", "3. A method of quantum communication", "4. A way to measure qubit entanglement"},
            {"1. Faster computation of complex problems", "2. Solving problems that are difficult for classical computers", "3. Cryptography", "4. All of the above"},
            {"1. IBM", "2. Google", "3. Microsoft", "4. All of the above"}
        },
        { // Robotics
            {"1. To automate tasks", "2. To replace human workers", "3. To assist in repetitive tasks", "4. All of the above"},
            {"1. A machine used in factories", "2. A machine that helps in healthcare", "3. A robot used in household tasks", "4. None of the above"},
            {"1. Reducing human intervention", "2. Replacing human workers", "3. Performing tasks remotely", "4. All of the above"},
            {"1. Robotic arms used in manufacturing", "2. Delivery robots", "3. Autonomous vehicles", "4. All of the above"},
            {"1. For movement and interaction", "2. For sensory input", "3. For controlling robots remotely", "4. None of the above"},
            {"1. AI controls robots", "2. Robotics builds physical devices", "3. Robotics enhances human tasks", "4. Both AI and robotics are needed for automation"},
            {"1. A tool used for interaction", "2. The part that manipulates objects", "3. The software that controls the robot", "4. None of the above"},
            {"1. Manufacturing", "2. Healthcare", "3. Logistics", "4. All of the above"},
            {"1. Improving accuracy", "2. Allowing robots to learn from experiences", "3. Making robots smarter", "4. All of the above"},
            {"1. AI-controlled robots", "2. Automated systems", "3. More advanced robots", "4. Robot-human collaboration"}
        }
    };

    
    int answers[9][10] = {
        {3, 2, 3, 1, 2, 1, 3, 2, 1, 1}, // AI and ML
        {1, 1, 4, 1, 3, 3, 2, 2, 1, 3}, // Cybersecurity
        {1, 2, 3, 4, 4, 3, 1, 3, 2, 4}, // IoT
        {2, 1, 2, 1, 2, 1, 1, 3, 2, 1}, // Blockchain
        {3, 1, 2, 3, 4, 3, 1, 2, 1, 3}, // Data Science
        {4, 1, 3, 4, 2, 2, 3, 1, 1, 2}, // Cloud Computing
        {2, 3, 1, 4, 1, 3, 1, 3, 1, 1}, // VR and AR
        {1, 2, 3, 4, 3, 4, 1, 2, 3, 4}, // Quantum Computing
        {3, 1, 2, 4, 1, 2, 2, 1, 1, 3}  // Robotics
    };

    int userAnswer;
    int questionIndex;

    for (questionIndex = 0; questionIndex < 10; questionIndex++) {
        clearScreen();
        printf("Subject: %s\n", subjects[subjectIndex]);
        printf("Question %d of %d: %s\n", questionIndex + 1, totalQuestions, questions[subjectIndex][questionIndex]);
        printf("1) %s\n", options[subjectIndex][questionIndex][0]);
        printf("2) %s\n", options[subjectIndex][questionIndex][1]);
        printf("3) %s\n", options[subjectIndex][questionIndex][2]);
        printf("4) %s\n", options[subjectIndex][questionIndex][3]);
        printf("Enter your answer (1-4): ");

        // Reading user's answer
        scanf("%d", &userAnswer);

        // Check if the user's answer is correct
        if (userAnswer == answers[subjectIndex][questionIndex]) {
            score += 10;
            displayCorrect();
        } else {
            displayFail();
            return;  
        }
    }

    
    if (score == totalQuestions * 10) {
        showWin();
    } else {
        showExitMessage();
    }
}

void displayCorrect() {
    printf("Correct!\n");
    printf("Your Score: %d\n", score);
    printf("Press any key to continue...\n");
    _getch();
}

void displayFail() {
    printf("Incorrect! You failed the quiz.\n");
    printf("Your Score: %d\n", score);
    printf("Redirecting to Home...\n");
    _getch();
    showMainMenu();  

void showWin() {
    clearScreen();
    printf("Congratulations! You won the quiz!\n");
    printf("Your Final Score: %d\n", score);
    printf("Press any key to return to the main menu...\n");
    _getch();
    showMainMenu();  
}

void showExitMessage() {
    clearScreen();
    printf("Thank you for playing the quiz!\n");
    printf("Your Final Score: %d\n", score);
    printf("Press any key to exit...\n");
    _getch();
    exit(0);  
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}
