# ===============================================
# ==============     UVa: 10142    ==============
# ===============================================


NumberOfTestCases = int(input())
input()

LastTestCase = False
for Case in range(0, NumberOfTestCases):
    
    # ==== DEFAULT VALUES ====
    NumberOfCandidates = int(input())
    CandidatesNames = []
    Votes = []
    Losers = set()

    # ==== READ THE NAMES ====
    for Candidate in range(0, NumberOfCandidates):
        CandidatesNames.append(input())

    # ==== READ THE VOTES ====
    while True:
        try:
            Temporal = input()
        except EOFError:
            LastTestCase = True
            break
            
        if Temporal.strip() == '': 
            break
        else: 
            Votes.append(list(map(int, Temporal.split())))

    # ==== REAL ALGORITHM: AKA SIMULATE ELECTION COUTING ====
    while (True):

        Rankings = [0 for Candidate in CandidatesNames]

        # ==== VOTATION TIME ====
        for Vote in Votes:
            for Candidate in Vote:
                if (Candidate - 1) in Losers: 
                    continue;
                else: 
                    Rankings[Candidate - 1] += 1
                    break;

        # ======  WINNER??  ====
        PossibleWinner = Rankings.index(max(Rankings))

        if Rankings[PossibleWinner] > 0.50 * sum(Rankings):
            print(CandidatesNames[PossibleWinner])
            break;

        RankingsWithoutLosers = [item for x, item in enumerate(Rankings) 
                            if x not in Losers]
                            
        # ======  TIE??  ====
        if len(set(RankingsWithoutLosers)) == 1:
            for index, CandidateVotes in enumerate(Rankings):
                if CandidateVotes == 0: 
                    continue

                print(CandidatesNames[index])

            break;

        # ======  TIE??  ====
        NewLoserVotes = min(RankingsWithoutLosers)

        for Candidate, CandidateVotes in enumerate(Rankings):
            if NewLoserVotes == CandidateVotes:
                Losers.add(Candidate)

    if (not LastTestCase): print("")
