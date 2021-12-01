#include<stdio.h>
#include<mpi.h>									// Inkludieren der MPI-Bibliothek, damit dir MPI Befehle funktionieren

int main(int argc, char** argv) {
	int nodeID, numNodes;

	/* MPI Funktionen */
	MPI_Init(&argc, &argv);						// Übergabe der Anzahl des Intergers und der Liste der Strings per Referenz, Bereinigung der Argumentliste
	MPI_Comm_size(MPI_COMM_WORLD, &numNodes);	// Aufruf der Funktion MPI_Comm_size, Übergabe Adresse des Intergers, Ausgabe der Anzahl an verfügbaren Prozessen
	MPI_Comm_rank(MPI_COMM_WORLD, &nodeID);		// Aufruf der Funktion MPI_Comm_rank, Übergabe Adresse des Intergers, Ausgabe der Prozess-ID 

	/* Ausgabe auf der Konsole
	printf funktioneirt nur durch das Inkludieren von stdio.h*/
	printf("Hello world from process %d of %d\n", nodeID, numNodes);

	/* MPI Laufzeitsystem wird beendet. Danach kann kein MPI Prozess mehr aufgerufen werden */
	MPI_Finalize();

	return 0;
}

