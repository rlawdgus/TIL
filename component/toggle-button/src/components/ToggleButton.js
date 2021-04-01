import React from 'react'

const ToggleButton = () => {
    return (
        <>
            <input type="checkbox" id="toggle" />
            <label for="toggle" className="contents">
                <div className="toggle-button" />
                <div className="toggle-button-back" />
            </label>
        </>
    )
}

export default ToggleButton