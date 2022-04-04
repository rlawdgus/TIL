import { fireEvent, render, screen } from "@testing-library/react";

import CounterState from "../components/CounterState";

describe("counter tests", () => {
    test("CounterState test", () => {
        // eslint-disable-next-line testing-library/render-result-naming-convention
        const counter = render(<CounterState />);

        fireEvent.click(screen.getByText("+1"));

        expect(counter).toMatchSnapshot();
    });
});
