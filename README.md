# DataSensorAnalyser II

Detta program är en vidareutveckling av Inlämningsuppgift 1 och är skrivet i C++.  
Programmet används för att samla in, lagra, analysera och visa mätvärden (t.ex. temperaturer).

I denna version har programmet strukturerats om med hjälp av klasser, structs och flera filer för att göra koden tydligare och lättare att underhålla.

/Projekt  
├── main.cpp  
├── menu.h  
├── menu.cpp  
├── measurement.h  
├── statistics.h  
├── data_manager.h  
├── data_manager.cpp  

Measurement (struct)
Representerar ett mätvärde och innehåller:
- float value – själva mätvärdet
- std::string timestamp – tidpunkt för mätningen

Statistics (struct)
Används för att lagra beräknad statistik:
- Medelvärde
- Minvärde
- Maxvärde
- Standardavvikelse

---

DataManager (klass)
Ansvarar för programmets huvudlogik:
- Lagrar mätvärden i en std::vector
- Lägger till nya mätvärden
- Beräknar statistik
- Skriver ut data och statistik
- Läser från och sparar till fil (data.csv)

---

Meny
Menylogiken är separerad från main.cpp och låter användaren:
1. Lägga till mätvärde  
2. Visa alla mätvärden  
3. Visa statistik  
4. Rensa alla mätvärden  
5. Spara och avsluta  

main.cpp
main.cpp är medvetet väldigt enkel och:
- Skapar ett DataManager-objekt
- Läser in data från fil vid start
- Startar menyloopen
  
Filhantering
Mätvärden sparas i en CSV-fil (data.csv) med formatet:

2025-10-07 09:00,22.5  
2025-10-07 10:00,23.1  

Filen läses automatiskt vid programstart och sparas när programmet avslutas.

Kompilering och körning
Exempel med g++:

g++ main.cpp menu.cpp data_manager.cpp -o matprogram  
./matprogram  

Uppfyllda krav
- Minst en klass (DataManager)
- Minst en struct (Measurement)
- Använder std::vector
- Beräknar statistik (medel, min, max, standardavvikelse)
- Filhantering (läsa och skriva till fil)
- Koden är uppdelad i flera filer
- Programmet kompilerar och körs utan fel

Kommentar
Programmet är uppdelat i små, tydliga delar för att vara lätt att förstå, felsöka och bygga vidare på.  
Strukturen gör det enkelt att lägga till fler funktioner i framtiden.
