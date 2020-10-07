import React from 'react'
import CheckBox from './CheckBox'

const CheckBoxList = ({ checkBoxes, onClick }) => {
    return (
        <>
        {checkBoxes.map(checkBox => (
            <CheckBox checked={checkBox.checked} key={checkBox.id} onClick={() => onClick(checkBox.id)} />
        ))}
        </>
    )
}

export default CheckBoxList