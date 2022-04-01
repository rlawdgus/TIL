import { fireEvent, render, screen } from "@testing-library/react";
import CounterState from "../components/CounterState";

test("counter", () => {
    render(<CounterState />);

    fireEvent.click(screen.getByText("+1"));

    expect(screen.getByTestId("state")).toMatchSnapshot();
});
