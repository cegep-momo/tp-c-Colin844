# Utiliser une image de base avec les outils de compilation C++
FROM gcc:latest

# Installer CMake et les dépendances nécessaires
RUN apt-get update && apt-get install -y \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

# Définir le répertoire de travail
WORKDIR /app

# Copier tous les fichiers du projet
COPY . .

# Créer un répertoire pour la compilation
RUN mkdir -p build

# Configurer et compiler le projet
WORKDIR /app/build
RUN cmake .. && make

# Retourner au répertoire principal
WORKDIR /app

# Commande par défaut pour exécuter l'application
CMD ["./build/bibliotheque"]