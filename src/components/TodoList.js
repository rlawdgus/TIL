import React, { useState } from "react";

const TodoList = () => {
    const [todos, setTodos] = useState([]);

    const onClick = () => {
        import("./Todo.js").then((Todo) => {
            const TodoItem = Todo.default;
            const position = todos.length + 1;
            const newTodo = <TodoItem key={position} title={`#${position}`} />;
            setTodos([...todos, newTodo]);
        });
    };

    return (
        <div>
            <button onClick={onClick}>+</button>
            {todos}
        </div>
    );
};

export default TodoList;
