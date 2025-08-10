# SNHU-CS-210
Portfolio Repository for CS 210 at SNHU

## Summarize the project and what problem it was solving.
This application allows customers from Airgead Bank to calculate the potential return of an investment. With optioins for modifying initial deposits, recurring monthly deposits, as well as the interest rate and term of the investment, this application gives a variety of data to empower users to make smarter investment decisions.

## What did you do particularly well?
The most interesting thing about this application is how easily it can be evolved. This appliction features three distinct layers - a main application layer, the investment and calculations of the business layer, and an isolation of the user interface into an IO layer. That separation of concern allows for each layer to be modified, while preserving the others. The IO layer could be quickly replaced by a set of endpoints, easily turning this application into an API, or the calculations could be modified, while still maintaining the current display formatting.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
The next set of enhancements for this appliction would involve adding persistance with a database or storage of some kind, and including user accounts to prevent users from interacting with the data of other customers. This would also provide the opportunity to include different types of user accounts, to allow employees to add information to a users account.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging thing to do with this application was separate values from references. When I started this project, I had intended to leverage C++'s capability of passing by reference to reduce the overall memory footprint of the application, but due to time and study limitations I opted to use passing by value. This ensured that I was able to include all the functionality I wanted to, but has the drawback of using more memory to run the application.

## What skills from this project will be particularly transferable to other projects or course work?
The most transferrable skill I got to practice for this project was separating my application into functional layers. As a PM and DevOpsSec specialist, I spend much of my time observing projects from the infrastructure and architecture standpoint, looking at service interactions. This was a fun practice for me to get to work on the application layers again!

## How did you make this program maintainable, readable, and adaptable?
The biggest factor in maintailability was to comment my code, and follow the "best-practices" buide in the application requirements. Following a teams standard practice for naming, commenting, and documenting means that any developer to follow me and work on this application should be albe to pick up where I've left off. Using verbose names, rather than obscure abbreviations makes it easier to identify the differnet objects, values, and purposes of anything in the application. Adaptability is achieved through layering the application, using classes with separate headers, and again: documenting EVERYTHING as you go.
