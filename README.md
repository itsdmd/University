# ✅ Status
## 💬 CMs Format
[![Generic CM Verifier](https://github.com/itsdmd/University/actions/workflows/gcmv.yml/badge.svg?branch=1.2)](https://github.com/itsdmd/University/actions/workflows/gcmv.yml) &emsp; [![Submission CM Verifier](https://github.com/itsdmd/University/actions/workflows/scmv.yml/badge.svg?branch=1.2)](https://github.com/itsdmd/University/actions/workflows/scmv.yml)

## 💎 Code Quality
[![CodeFactor](https://www.codefactor.io/repository/github/itsdmd/university/badge)](https://www.codefactor.io/repository/github/itsdmd/university) &emsp; ![CodigaScore](https://api.codiga.io/project/32682/score/svg)

# 📜 Table of Contents
- **[🏷️ Naming Schemes](#%EF%B8%8F-naming-schemes)**
	- **[1. 🌿 Branches](#1--branches)**
	- **[2. 📁 Folders](#2--folders)**
	- **[3. 📄 Files](#3--files)**
	- **[4. 💬 Commit Messages](#4--commit-messages)**
		- **[a. 📚 Generic](#a--generic)**
		- **[b. ✍ Submission](#b--submission)**

# 🏷️ Naming Schemes
## 1. 🌿 Branches
Follow format: ```<year>.<semester>```

Eg.: First year, second semester will be ```1.2```

## 2. 📁 Folders
There should be a folder for each course. The name of the folder should be the course code.

General hierarchy (only folder's level matters):
- **Course**
	- **exc** ................. *for homework assignments*
		- ├ **.vscode** + Workspace file
		- ├ **L** .................. *Lab*
		- └ **T** ...................*Theory*
		
			- ├ **codes** ............... *Code submission*
			- └ **subs** ................. *Other submission*
			
				- └ **W\*\*** .................. *Week \*\* submission, ex: W03*
	---
	- **lec** .................... *for lecture materials*
		- ├ **L** ............... *Lab*
		- └ **T** ............... *Theory*
			- └ **W\*\*** .................. *Week \*\* lecture/resource*

## 3. 📄 Files
**For material files**: Descriptive and no whitespace

**For submission files**: Follow lecturer's naming scheme

## 4. 💬 Commit Messages
There are 2 types of commits: ***Generic*** and ***Submission***.
- **[Generic](#a--generic)**: For files that are not submissions. Check using [GMCV workflow](https://github.com/itsdmd/University/actions/workflows/gcmv.yml).
- **[Submission](#b--submission)**: For files that are for homework submission. Check using [SCMV workflow](https://github.com/itsdmd/University/actions/workflows/scmv.yml).

### a. 📚 Generic
Generic commits must start its message with one of the following prefixes:

- ```[add]``` : Create new
- ```[del]``` : Delete
- ```[mod]``` : Modify *(non-versioning CMs only)*
- ```[rnm] <old> > <new>``` : Rename
- ```[mov] <old_dir> > <new_dir>``` : Move
- ```[rft]``` : Directory refactor
- ```[mrg] <from> > <to>``` : Branch merging

### b. ✍ Submission

```
               (1)              |                                  (2)                                      |          (3)
 -------------------------------+---------------------------------------------------------------------------+------------------------
      req. if (3) is missing	|                                required                                   | only if (1) is missing
 -------------------------------+---------------------------------------------------------------------------+------------------------
     [|3 characters|]|*space*	|  3 digits|*dot*|'L' OR 'T'|*dot*|2 digits AND characters that's not '.'   |    |*dot*|2 digits|
                            	| (+1 char)                                     if (1) exists (optional)    |
 -------------------------------+---------------------------------------------------------------------------+------------------------
              [add]             |                                104.L.01                                   |          .02
        
```

✅ Match:
- ```102.02.01```
- ```104.L.02.01```
- ```105b.T.03.02```
- ```[add] 102.05```
- ```[add] 104.T.05```
- ```[add] 104.T.05-og```
- ```[rnm] 104.T.05 > 104.T.06.31```

❌ Won't match:
- ```104.T.03```
- ```[xyz] 104.T.05```
- ```[rnm] 104.T.05```
- ```[mod] 104.T.05.21```
- ```104.l.02.01```
- ```104.X.02.03```
- ```[del] 42069.LT.2.112```