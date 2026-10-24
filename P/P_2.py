from decimal import Decimal, ROUND_HALF_UP

"""
CHALLENGE 2: Registro Contabile (Bank Ledger)
-----------------------------------------------------------
OBIETTIVO:
Implementare la classe `BankAccount` che gestisce depositi, prelievi e storico
delle transazioni, garantendo:
1. Nessuna contaminazione di dati tra conti correnti diversi.
2. Precisione finanziaria esatta (nessun errore di arrotondamento float tipo 0.1 + 0.2 != 0.3).
3. Saldo sempre coerente con la somma delle transazioni registrate.
"""

class BankAccount:
    def __init__(self, owner: str, initial_balance=0.0, transactions=[]):
        self.owner = owner
        self.balance = float(initial_balance)
        self.transactions = transactions

        if initial_balance > 0:
            self.transactions.append(("DEPOSIT", initial_balance))

    def deposit(self, amount: float) -> bool:
        if amount <= 0:
            return False
        self.balance += amount
        self.transactions.append(("DEPOSIT", amount))
        return True

    def withdraw(self, amount: float) -> bool:
        if amount <= 0:
            return False

        self.transactions.append(("WITHDRAW", amount))

        if self.balance < amount:
            return False

        self.balance -= amount
        return True

    def get_balance(self) -> float:
        # Ritorna il saldo arrotondato a 2 cifre decimali
        return round(float(self.balance), 2)


# ==============================================================================
# SUITE DI TEST (Non modificare i test! Devono passare tutti dopo le correzioni)
# Esegui con: python P_2.py
# ==============================================================================
if __name__ == "__main__":
    print("Verifica BankAccount...")

    # Test 1: Isolamento delle transazioni tra istanze diverse
    acc1 = BankAccount("Alice", 100.0)
    acc2 = BankAccount("Bob", 50.0)

    acc1.deposit(25.0)

    assert len(acc1.transactions) == 2, "ERRORE: Alice dovrebbe avere esattamente 2 transazioni!"
    assert len(acc2.transactions) == 1, "ERRORE: Bob ha ereditato le transazioni di Alice! Correggi l'argomento mutabile."

    # Test 2: Prelievo con fondi insufficienti
    success = acc2.withdraw(500.0)
    assert not success, "ERRORE: Il prelievo doveva fallire per fondi insufficienti!"
    assert len(acc2.transactions) == 1, "ERRORE: I prelievi falliti NON devono essere registrati nello storico!"
    assert acc2.get_balance() == 50.0

    # Test 3: Precisione decimale finanziaria
    acc3 = BankAccount("Charlie", 0.0)
    # Aggiungiamo 0.1 per tre volte: 0.1 + 0.1 + 0.1 deve essere esattamente 0.3!
    acc3.deposit(0.1)
    acc3.deposit(0.1)
    acc3.deposit(0.1)
    acc3.withdraw(0.3)

    assert acc3.get_balance() == 0.0, f"ERRORE di precisione float! Saldo: {acc3.get_balance()} != 0.0"

    print("[COMPLIMENTI] Tutti i test di BankAccount sono superati!")
