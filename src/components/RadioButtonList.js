import React, { useState, useCallback } from 'react'
import RadioButton from './RadioButton'

const RadioButtonList = () => {
    const [radios, setRadios] = useState([
        {
            id: 1,
            checked: false
        },
        {
            id: 2,
            checked: false
        },
        {
            id: 3,
            checked: false
        },
        {
            id: 4,
            checked: false
        },
        {
            id: 5,
            checked: false
        }
    ])

    const onClick = useCallback(id => {
        setRadios(
            radios.map(radio =>
                radio.id === id ? {...radio, checked: true} : {...radio, checked: false}
            )
        )
    }, [radios])

    return (
        <>
            {radios.map(radio => (
                <RadioButton onClick={onClick} radio={radio} key={radio.id}/>
            ))}
        </>
    )
}

export default RadioButtonList;