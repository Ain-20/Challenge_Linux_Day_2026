# ==============================================================================
# Makefile per Challenge di Programmazione C (Linux Day 2026)
# ==============================================================================
# Gestisce la compilazione del codice utente (C_X.c), la protezione/esecuzione
# del binario della soluzione precompilato (.solutions/sol_X) e il confronto
# automatico degli output.
# ==============================================================================

CC        := gcc
CFLAGS    := -Wall -O2
BUILD_DIR := build
SOL_DIR   := .solutions

# Colori terminale ANSI
GREEN  := \033[1;32m
RED    := \033[1;31m
YELLOW := \033[1;33m
CYAN   := \033[1;36m
RESET  := \033[0m

IDS := 1 2 3 4 5 6 7 8 9 10

.PHONY: all help prepare-solutions check check-all clean distclean

all: help

help:
	@echo "$(CYAN)==================================================================$(RESET)"
	@echo "$(CYAN)           TEST HARNESS SFIDE IN C - COMANDI DISPONIBILI          $(RESET)"
	@echo "$(CYAN)==================================================================$(RESET)"
	@echo "  $(GREEN)make check-1$(RESET) (oppure make check-2, ..., make check-10)"
	@echo "      Compila C_X.c dell'utente e confronta l'output con la soluzione."
	@echo ""
	@echo "  $(GREEN)make 1$(RESET) (oppure make 2, ..., make 10)"
	@echo "      Scorciatoia rapida numerica per verificare la challenge."
	@echo ""
	@echo "  $(GREEN)make check C=1$(RESET)  (ATTENZIONE: senza spazi attorno a '=')"
	@echo "      Esegue la verifica per la challenge specificata."
	@echo ""
	@echo "  $(GREEN)make check-all$(RESET)"
	@echo "      Verifica tutte le challenge da 1 a 10 in sequenza."
	@echo ""
	@echo "  $(YELLOW)make prepare-solutions$(RESET)  (Uso docente/organizzatore)"
	@echo "      Compila le soluzioni in $(SOL_DIR)/, rimuove i simboli (strip)"
	@echo "      e predispone i permessi di sola esecuzione (chmod 711)."
	@echo ""
	@echo "  $(YELLOW)make clean$(RESET)"
	@echo "      Elimina file oggetto, output temporanei e la cartella $(BUILD_DIR)/."
	@echo "$(CYAN)==================================================================$(RESET)"

# ------------------------------------------------------------------------------
# 1. PREPARAZIONE DELLE SOLUZIONI (Docente / Organizzatore)
# ------------------------------------------------------------------------------
prepare-solutions:
	@mkdir -p $(SOL_DIR)
	@echo "$(CYAN)[*] Compilazione e protezione delle soluzioni di riferimento...$(RESET)"
	@for i in $(IDS); do \
		if [ -f "C_$${i}_sol.c" ]; then \
			$(CC) $(CFLAGS) "C_$${i}_sol.c" -o "$(SOL_DIR)/sol_$${i}"; \
			strip -s "$(SOL_DIR)/sol_$${i}"; \
			chmod 711 "$(SOL_DIR)/sol_$${i}"; \
			echo "  -> Soluzione C_$${i}: compilata in $(SOL_DIR)/sol_$${i} (chmod 711, stripped)"; \
		else \
			echo "  [!] Avviso: C_$${i}_sol.c non trovato, saltato."; \
		fi \
	done
	@echo "$(GREEN)[+] Preparazione completata!$(RESET)"
	@echo "    Puoi ora proteggere i sorgenti con: chmod 600 C_*_sol.c (o nasconderli)."

# ------------------------------------------------------------------------------
# 2. SCORCIATOIE E VERIFICA SINGOLA CHALLENGE
# ------------------------------------------------------------------------------
# Scorciatoie numeriche: make 1, make 2, ..., make 10
1 2 3 4 5 6 7 8 9 10: %: check-%

# Supporto a: make check C=1 oppure make check N=1
check:
	@TARGET_NUM="$(or $(C),$(N))"; \
	if [ -z "$$TARGET_NUM" ]; then \
		echo "$(RED)[ERRORE] Specificare la challenge da verificare.$(RESET)"; \
		echo "Esempi corretti:"; \
		echo "  make check-1"; \
		echo "  make 1"; \
		echo "  make check C=1  (senza spazi attorno al '=')"; \
		exit 1; \
	else \
		$(MAKE) --no-print-directory check-$$TARGET_NUM; \
	fi

# Regola per check-1, check-2, ..., check-10
check-%:
	@mkdir -p $(BUILD_DIR)
	@NUM="$*"; \
	USER_SRC="C_$${NUM}.c"; \
	USER_BIN="$(BUILD_DIR)/user_$${NUM}"; \
	SOL_BIN="$(SOL_DIR)/sol_$${NUM}"; \
	SOL_SRC="C_$${NUM}_sol.c"; \
	\
	echo "$(CYAN)=== Verifica Challenge C_$${NUM} ===$(RESET)"; \
	if [ ! -f "$$USER_SRC" ]; then \
		echo "$(RED)[ERRORE] File utente $$USER_SRC non trovato!$(RESET)"; \
		exit 1; \
	fi; \
	\
	echo "  [*] Compilazione file utente: $$USER_SRC..."; \
	if ! $(CC) $(CFLAGS) "$$USER_SRC" -o "$$USER_BIN"; then \
		echo "$(RED)[FAIL] Errore di compilazione nel file utente $$USER_SRC.$(RESET)"; \
		exit 1; \
	fi; \
	\
	if [ ! -f "$$SOL_BIN" ]; then \
		if [ -f "$$SOL_SRC" ]; then \
			echo "  [*] Soluzione precompilata assente: compilo da $$SOL_SRC..."; \
			mkdir -p $(SOL_DIR); \
			$(CC) $(CFLAGS) "$$SOL_SRC" -o "$$SOL_BIN"; \
			strip -s "$$SOL_BIN"; \
			chmod 711 "$$SOL_BIN"; \
		else \
			echo "$(RED)[ERRORE] Soluzione precompilata $$SOL_BIN non trovata! Eseguire prima 'make prepare-solutions'.$(RESET)"; \
			exit 1; \
		fi; \
	fi; \
	\
	echo "  [*] Esecuzione e confronto output..."; \
	if [ "$$NUM" = "1" ]; then \
		rm -f sol_utente soluzione1; \
		./"$$USER_BIN" > /dev/null 2>&1; \
		./"$$SOL_BIN" > /dev/null 2>&1; \
		if [ -f sol_utente ] && [ -f soluzione1 ] && cmp -s sol_utente soluzione1; then \
			echo "$(GREEN)[CORRETTO] Challenge C_1: L'output coincide con la soluzione!$(RESET)"; \
		else \
			echo "$(RED)[ERRATO] Challenge C_1: Il file sol_utente differisce da soluzione1.$(RESET)"; \
		fi; \
		rm -f sol_utente soluzione1; \
	else \
		USER_OUT="$(BUILD_DIR)/user_$${NUM}.out"; \
		SOL_OUT="$(BUILD_DIR)/sol_$${NUM}.out"; \
		./"$$USER_BIN" > "$$USER_OUT" 2>&1; \
		./"$$SOL_BIN" > "$$SOL_OUT" 2>&1; \
		if diff -u "$$USER_OUT" "$$SOL_OUT" > "$(BUILD_DIR)/diff_$${NUM}.txt"; then \
			echo "$(GREEN)[CORRETTO] Challenge C_$${NUM}: L'output coincide perfettamente con la soluzione!$(RESET)"; \
			cat "$$SOL_OUT"; \
		else \
			echo "$(RED)[ERRATO] Challenge C_$${NUM}: L'output differisce dalla soluzione.$(RESET)"; \
			echo "$(YELLOW)--- Differenze riscontrate (Atteso vs Ottenuto) ---$(RESET)"; \
			head -n 25 "$(BUILD_DIR)/diff_$${NUM}.txt"; \
		fi; \
	fi

# ------------------------------------------------------------------------------
# 3. VERIFICA DI TUTTE LE CHALLENGE (1..10)
# ------------------------------------------------------------------------------
check-all:
	@echo "$(CYAN)==================================================================$(RESET)"
	@echo "$(CYAN)              AVVIO VERIFICA DI TUTTE LE CHALLENGE               $(RESET)"
	@echo "$(CYAN)==================================================================$(RESET)"
	@for i in $(IDS); do \
		$(MAKE) --no-print-directory check-$$i; \
		echo ""; \
	done

# ------------------------------------------------------------------------------
# 4. PULIZIA
# ------------------------------------------------------------------------------
clean:
	@rm -rf $(BUILD_DIR) user solution user_output.txt solution_output.txt sol_utente soluzione1
	@echo "$(GREEN)[+] Pulizia completata!$(RESET)"

distclean: clean
	@rm -rf $(SOL_DIR)
	@echo "$(GREEN)[+] Pulizia profonda completata! (Rimosso anche $(SOL_DIR))$(RESET)"
