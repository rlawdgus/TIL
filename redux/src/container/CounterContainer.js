import React from 'react'
import useCounter from '../hooks/useCounter'

const CounterContainer = () => {
    const [num, increase, decrease] = useCounter();
    return (
        <>
            {num}
            <button onClick={increase}>Increase</button>
            <button onClick={decrease}>Decrease</button>
        </>
    )
}

export default CounterContainer