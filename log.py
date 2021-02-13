import os


def parse_problem(problem_folder):
    algorithm_info_path = os.path.join(problem_folder, "algorithm.list")
    algorithm_dict = {}
    with open(algorithm_info_path, "r", encoding="utf-8") as fp:
        lines = fp.readlines();
        for line in lines:
            tmp = line.strip().split("$")
            assert len(tmp) == 2
            algorithm_dict[tmp[0]] = tmp[1]

    return algorithm_dict

if __name__ == "__main__":
    base_folder = "leetcode"
    base_url = "https://leetcode-cn.com/problems/"

    problem_list = os.listdir(base_folder)
    problem_list = sorted(problem_list, key=lambda x: int(x.split(".")[0]))

    with open("leetcode.log", "w") as fp:
        for problem in problem_list:
            problem_name = problem.split()
            problem_name = "-".join(problem_name[1:])
            problem_url = f"{base_url}{problem_name}/"
            problem_folder = os.path.join(base_folder, problem)
            algorithm_dict = parse_problem(problem_folder)
            # problem head
            fp.write(f"* [{problem}]({problem_url})\n")
            index = 0
            for key in algorithm_dict.keys():
                index += 1
                fp.write(f"    * [{index}) {algorithm_dict[key]}](leetcode/{problem.replace(' ', '%20')}/{algorithm_dict[key]})\n")

