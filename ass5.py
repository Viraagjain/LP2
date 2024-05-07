import random
import re

responses = {
    'greeting': [
        'Hello, and welcome to lifeline Hospital. How can we assist you today?',
        'Hi there! How may I help you with your healthcare needs?',
        'Welcome! Do you have a specific medical concern or inquiry?',
    ],

    'farewell': [
        'Thank you for choosing lifeline Hospital! We wish you a speedy recovery.',
        'We appreciate your visit. Take care and stay healthy!',
        'Your well-being is important to us. If you have any more questions, feel free to ask.',
    ],

    'about_services': [
        'Have you been to our hospital before, or is this your first visit?',
        'Are you seeking information about our specialized medical services?',
        'We offer a range of healthcare services, from general check-ups to specialized treatments.',
    ],

    'appointment': [
        'Let me check for available appointment slots with our medical professionals.',
        'Do you have a preferred date and time for your medical appointment?',
        'Would you like assistance in scheduling a consultation with one of our doctors?',
    ],

    'after_consultation': [
        'How was your consultation? Do you have any follow-up questions or concerns?',
        'Would you like a copy of your medical records or prescriptions?',
        'Is there anything else we can assist you with regarding your health?',
    ],

    'default': [
        "I'm sorry but I didn't fully understand your request.",
        "I apologize if my response was unclear. Could you please provide more details?",
        "I'm here to help with any questions you have about our hospital and services.",
    ],
}


def respond(inquiry):
    inquiry = inquiry.lower()

    if re.search(r"\b(?:hello|hi)\b", inquiry):
        return random.choice(responses['greeting'])

    elif re.search(r"\b(?:goodbye|bye)\b", inquiry):
        return random.choice(responses['farewell'])

    elif re.search(r"\b(?:about|services)\b", inquiry):
        return random.choice(responses['about_services'])

    elif re.search(r"\b(?:appointment|schedule)\b", inquiry):
        return random.choice(responses['appointment'])

    elif re.search(r"\b(?:after|consultation)\b", inquiry):
        return random.choice(responses['after_consultation'])

    elif inquiry == 'yes' or inquiry == 'Yes':
        return 'Great! If you have any more questions or need assistance, feel free to ask.'

    else:
        return random.choice(responses['default'])


print("Welcome to lifeline Hospital Customer Interaction Chatbot!")
print("Type 'exit' to end the conversation.\n")

while True:
    user_input = input("Patient: ")

    if user_input.lower() == 'exit':
        break

    if user_input.lower() == 'bye' or user_input.lower() == 'goodbye':
        break

    bot_response = respond(user_input)
    print("Hospital Bot: ", bot_response)

print('\nThank you for interacting with lifeline Hospital Chatbot. Take care of your health!')