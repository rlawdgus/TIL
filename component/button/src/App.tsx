import Button from "./Button";

const App = () => {
    const onClick = () => {
        console.log("onClick");
    };

    return (
        <Button type="button" className="class-name" onClick={onClick}>
            Button
        </Button>
    );
};

export default App;
