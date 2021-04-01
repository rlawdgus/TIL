import React from 'react'

const RadioButton = ({ onClick, radio }) => {
    const radioClass = radio.checked ? "checked" : ""

    return (
        <div onClick={() => onClick(radio.id)} className={"radio-button " + radioClass}/>
    )
}

export default RadioButton