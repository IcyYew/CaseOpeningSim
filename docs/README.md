# CaseOpeningSim
Simulating ROI and profit margins for CS2 case openings, with a focus on modeling how profitable (or unprofitable :/) various cases on gambling sites are over large numbers of trials.

## Featuring
- **Concurrent simulation with pthreads**

  Run numerous independent trials in parallel for fast statistical modeling of case openings.
- **xoshiro256++ PRNG with Wincrypt seeding**

  High quality seeding with Windows Cryptographic API, wtih quick, statistically proven random number generation by xoshiro256++.
- **Scalable case definitions**

  Add new cases without touching core logic by defining them via prompt or importing via CSV.
  Newly added cases, regardless of origin are added to local efficiently formatted case "database" CSV with clean and consistent error handling.
- **"Smart" local logging**

  Automatically logs results for user-created caes to a local file for later analysis.
- **"Smart" interpreter / importer (CSV)**

  Read user defined cases in CSV files, cleanup inconsistencies and check for anomalous/erroneous inputs in case context.
  Add to local "database" CSV.

---


## Building
Instructions here...

### Requirements
- Windows
- C compiler
- pthread library


---


## CSV Formatting Instructions
Instructions here...


---


## My Own Statistical Analysis
Graphs and stuff here


---


## WBS
[WBS](WBS.txt)


## Licensing
Free use! Public domain!
