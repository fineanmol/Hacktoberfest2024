const statuses = {
	notStarted: 0,
	inProgress: 1,
	done: 2
}

console.log(statuses.inProgress)

enum StatusEnum {
	NotStarted = "notStarted",
	inProgress = "inProgress",
	Done = "done"
}

interface Task {
	id: string;
	status: StatusEnum;
}

const taskObj: Task = {
	id : "stringAirite",
	status : StatusEnum.Done
} // enums can be used to restrict values to one type only (that is status can only have the 3 values defined in StatusEnum, and nothing else)

let notStartedStatus: StatusEnum = StatusEnum.NotStarted
notStartedStatus = StatusEnum.Done
