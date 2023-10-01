import os
import torch
import torchaudio
import pyaudio
import wave

from torch import nn


def record_audio(duration=5, sample_rate=44100, channels=1):
    audio = pyaudio.PyAudio()

    try:
        stream = audio.open(
            format=pyaudio.paInt16,
            channels=channels,
            rate=sample_rate,
            input=True,
            frames_per_buffer=1024,
        )

        print("Recording...")

        frames = []
        for i in range(0, int(sample_rate / 1024 * duration)):
            data = stream.read(1024)
            frames.append(data)

        print("Finished recording.")

        stream.stop_stream()
        stream.close()

        audio.terminate()

        # Create the output folder if it doesn't exist
        output_folder = "mic_records/"
        if not os.path.exists(output_folder):
            os.makedirs(output_folder)

        # Check if the file already exists, if yes, increment the index
        i = 0
        while True:
            filename = "recorded_audio"
            output_filename = f"{filename}_{i}.wav"
            audio_path = os.path.join(output_folder, f"{output_filename}")
            if not os.path.exists(os.path.join(output_folder, output_filename)):
                break
            i += 1

        # Save the audio to a WAV file with the new filename
        output_path = os.path.join(output_folder, output_filename)
        with wave.open(output_path, "wb") as wf:
            wf.setnchannels(channels)
            wf.setsampwidth(audio.get_sample_size(pyaudio.paInt16))
            wf.setframerate(sample_rate)
            wf.writeframes(b"".join(frames))
    except Exception as e:
        print("An error occurred:", str(e))

    return audio_path


# Record audio as input file
input_audio = record_audio()

# Setup device agnostic code
if torch.backends.mps.is_available():
    device = "mps"
elif torch.cuda.is_available():
    device = "cuda"
else:
    device = "cpu"

# Setup feature extractor model
bundle = torchaudio.pipelines.WAV2VEC2_ASR_BASE_960H
model = bundle.get_model().to(device)

waveform, waveform_rate = torchaudio.load(input_audio)

waveform = waveform.to(device)
model = model.to(device)
if waveform_rate != bundle.sample_rate:
    waveform = torchaudio.functional.resample(
        waveform, waveform_rate, bundle.sample_rate
    )

with torch.inference_mode():
    emission, _ = model(waveform)


class GreedyCTCDecoder(nn.Module):
    def __init__(self, labels, blank=0):
        super().__init__()
        self.labels = labels
        self.blank = blank

    def forward(self, emission):
        """Given a sequence emission over labels, get the best path string
        Args:
        emission (Tensor): Logit tensors. Shape `[num_seq, num_label]`.
        Returns:
        str: The resulting transcript
        """
        indices = torch.argmax(emission, dim=1)
        indices = torch.unique_consecutive(indices, dim=-1)
        indices = [i for i in indices if i != self.blank]
        return "".join([self.labels[i] for i in indices])


decoder = GreedyCTCDecoder(bundle.get_labels(), blank=0)
transcript = decoder(emission[0])
print(transcript)
