package awale.ai;

import awale.action.Action;

public class TaskResult {

	public Action action;
	public int value;

	public TaskResult(Action action, int value) {
		this.action = action;
		this.value = value;
	}

}